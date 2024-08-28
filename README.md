![Prey - programming language](logo.svg)

Prey - programming language.
[license - APACHE 2.0](LICENSE)

# Prey - programming language. Current version 0.15.12.

# To run programs do followings:
- run `sh <path-to-prey.sh-script> <path-to-source-code>`
- example: `sh prey.sh ./examples/hello-world`

# Key features:
- fast compiler - no slow runtime.
- high level abstraction.
- unlimited runtime speed which is achieved by unique architecture. It can compile code to any language as intermediary and harness its power. Current supported languages: `c++`.
- universal application. Current supported area of applications: `back-end`, `service`.
- maximum protection from runtime and compile errors.
- unique scope and namespace architecture unleashes full potential of encapsulation and unite files directory into one consummate program.
- beauty, simplicity and strictness of syntax.
- modern language features and syntax sugars.

# Motivations. As programs grow in size and complexity - modern languages should:
- limit user's actions to provide best code predictability and readability.
- check possible run time errors at compile time to increase program's security and reliability.
- provide modern features such that: concurrent and asynchronous programming, reactivity, native utility functions (filter, map, ...), syntax sugar (macros, decorators, ...) and so on.
- provide plain syntax to get rid of possible syntax's ambiguities and obscurities.
- be as fast as possible to solve specific tasks.

## I hope, this language can meet all requirements above.

# Language terms.
- `Scope` - lines of codes on which special rules are applied. These rules differ and depend on `scope` type, and applied `modifiers`. Scopes separated by tabs and starts after special word is applied. Examples: file `scope` - 0 tab, class `scope` - 1 tab, class public `scope` - 2 tabs.
- `Context` - lines of code starting from line 1 to current interested line. Context depends on interested line and can effect on variables visibility for `scopes` and so on.
- `Modifier` - special language attribute (macro) which tells compiler how to handle line or scope on which `modifier` is applied. Modifiers are prefixed by `@` symbol, therefore they can be considered as native `decorators`.
- `Term` - special code's part which has independent of another code line meaning
- `Callable variable` - variable which can be used as called term and return instance, void or primitive. `Classes` and `functions` are callable variables. To call variable, need to provide `(...)` in the end. Callable variables receive parameters by order or by name. Parameter is a variable inside callable scope.
- `Primitive` - variable, which construction is handled natively by compiler, You don't need to call `class` explicitly.

# Language keywords.
- OOP: `class`.
- Operators: `=`, `+`, `++`, etc.
- Scope modifiers: `@import`, `@enum`, `@public`, `@let` etc.
- Scopes: `class`, `if`, `while`, etc.
- Line side effect: assignment and variable calling.
- Scope operator: break, continue, =>, etc.

# Language syntax rules.
- All files must be named in PascalCase.
- Program must have `Main` file.
- File must contain only one entity (class, enum class, static class, etc.).
- Scope must be detached from one another with tabs. New scope inside another scope must have one tab more than previous one.
- Every term must be separated from another term with one space.

# Language types.
- integer
- float
- boolean
- string
- RE (Regular Expression)
- <ClassName\>

# Languages features. 0.1.0.
- <ClassName\> = <FileName\>, you don't need to specify <ClassName\> inside file.
- `@import` scope modifier - allows to insert another class into current class, every new folder acts as scope modifier and joins all previous folders to import path, operator `.` refers to current directory. All imports have absolute structure and starts from root (where `Main` file is located).
```
@import
  .Test
  utils
    Utils
```
- `class` key word - initialize class `scope`. Start current  scope and apply class rules, they include:
1. Class fields can have the following modifiers: `let`, `read`, `react`, `get`, `public` - field always available in class and class instance, `guarded`  - field used as `public` in class and as `private` in class instance, `private` - field only available in class.
2. All fields have `private` and `read` access by default.
3. Available inner scopes: only for class - `@extends`, `@params`, `@static`, `@react`, `@get`, `@public`, `@guarded`, `@fun`, `@let`. `@let` and `@read` are also available in other scopes.
4. Available lifecycle hooks: `init` - is called after class is called, `destroy` - is called before memory for class instance be released. They must return void.
5. All variables inside class should have camelCase.
6. Class has `@private` access for importing in current repository by default. available import access scope modifiers for class: `@private` - available only in current directory and deeper, `@guarded` - available only in current directory and directory one level above, and deeper, `@public` - available everywhere, `@onlyUp` available only in upper directories without any descent.
```
@import
  .InheritanceOne
  .InheritanceTwo

@onlyUp
class
  @params
    a: float
    b: float
    c = 111
    d = 777
  @extends
    InheritanceOne
    InheritanceTwo

  @public
    x = a + b + c + d

    @fun
      test: void
        print(x)
        print(y)
        print(z)
```
- `@params` scope modifier - modify current callable variable scope to declare params of this callable variable and apply following rules:
1. All params have `read` and additionally `private` for class access by default.
2. Available inner scopes: `@let`, and additionally `@public`, `@guard` for class.
3. Shortcut property assignment - if `=` operator is not provided, value and key are considered equal.
```
class
  @params
    a: float
    b: float
    c = 111
    d = 777

  @public
    y = a + b + c + d
```
- `@extends` class scope modifier - modify current scope to join other class structure and apply following rules:
1. This scope can only include the list of class of the same type (class, enum class, static class, etc.) in column.
```
@import
  .ShortcutEnum

@public
@enum
class
  @extends
    ShortcutEnum

  bicycle
```
- `@enum` class modifier - modify current class scope to enum and apply enum rules, they include: 
1. At the same time class fields can be only one of 3 types: `integer`, `boolean` or `string`.
2. All fields have `public` access.
3. Available inner scopes: `@extends`. 
4. Shortcut property assignment - if `=` operator is not provided, value and key are considered equal.
```
@import
  .ShortcutEnum

@public
@enum
class
  @extends
    ShortcutEnum

  bicycle
```
- `@fun` scope modifier - modify current scope to function scope and apply function rules, they include:
1. All fields can have either `@let` or `@read` access.
2. All fields have `private` access.
3. Available inner scopes: `@let`, `@read`, `@params`, `while`, `if`, `esle if`, `else`, `switch`.
4. `=>` - return operator.
5. Function can return all types.
```
    @fun
      @include(letFields.x)
      effect: void
        print(letFields.x)

      test: integer
        @params
          @let
            aa: integer
            bb: integer
          c = 1
          d = `Hello world`

        aa += 1
        bb += 1

        @read
          fourthParams = Params(0, 0)
          scOne = SelfCall(1)
          scTwo = SelfCall(2)
          scResult = scOne.add(scTwo)

        print(thirdParams.x)
        print(thirdParams.y)
        print(fourthParams.z)
        print(d)
        utils.utility()
        print(utils.x)
        print(length(d))
        libraryConflict.test()
        print(StaticFields.x)
        print(scResult.a)
        ifScopeOne.test()
        ifScopeTwo.test()
        whileScope.test()
        switchScope.test()
        reFields.test()
        namedArgumentsScope.test()
        print(ShortcutEnum.car)
        print(InheritedEnum.bicycle)
        print(NumberEnum.z)

        letFields.x = 666

        => a + b + c

      init: void
        a += 1
        b += 1

        @read
          c = test(a, d)

        print(c)
```
- every code line can be one of the following types at the same time: empty line, comment, scope modifier, line side effect, scope operator.
- `@let` scope modifier - modify current scope and apply following rules:
1. declare with assignment operator a variable with `let` access (mutable). One variable declaration per line.
```
@public
@enum
class
  @let
    x = 111
```
- `@read` scope modifier - modify current scope and apply following rules:
1. declare with assignment operator a variable with `read` access (immutable). One variable declaration per line.
```
@public
@enum
class
  x = 111
```
- `@react` class scope modifier - modify current scope and apply following rules:
1. declare with assignment operator a variable with `react` access (immutable and recomputed every time a variable, on which it depends, changes). One variable declaration per line.
```
@public
@enum
class
  @let
    x = 111
  @react
    y = 111 + x
```
- `@get` class scope modifier - modify current scope and apply following rules:
1. declare with assignment operator a variable with `get` access (immutable and recomputed every time it's used). One variable declaration per line.
```
@public
@enum
class
  @get
    y = random()
```
- `if` scope modifier - modify current scope and apply following rules:
1. Should take `boolean` expression.
2. Scope is read if expression return true.
3. Inside this scope all `fun` modifiers are available. 
4. All fields have `private` access.
```
@onlyUp
class
  @params
    x = 777
  @public
    @fun
      test: void
        if x == 777
          print(`true`)
        else if x == 666
          print(`false`)
        else
          print(`nor false nor true`)
```
- `else if` scope modifier - modify current scope and apply following rules:
1. Should take `boolean` expression.
2. Scope is read if previous `if` or `else-if` aren't read and expression return true.
3. Inside this scope all `fun` modifiers are available.
4. All fields have `private` access.
5. Cannot apply this modifier if there is no `if` modifier in chain.
```
@onlyUp
class
  @params
    x = 777
  @public
    @fun
      test: void
        if x == 777
          print(`true`)
        else if x == 666
          print(`false`)
        else
          print(`nor false nor true`)
```
- `else` scope modifier - modify current scope and apply following rules:
1. Should not take expression.
2. Scope is read if previous `if` or `else-if` aren't read and expression return true.
3. Inside this scope all `fun` modifiers are available.
4. All fields have `private` access.
5. After this scope `else if` modifier cannot be used. 
6. Cannot apply this modifier if there is no `if` modifier in chain.
```
@onlyUp
class
  @params
    x = 777
  @public
    @fun
      test: void
        if x == 777
          print(`true`)
        else if x == 666
          print(`false`)
        else
          print(`nor false nor true`)
```
- `switch` scope modifier - modify current scope and apply following rules:
1. Should take primitive variable.
2. No line side effects are allowed.
3. No scope operators are allowed.
4. Inside this scope only following scope modifiers are available: `case` - takes primitive expression, `match` - takes regular expression primitive, `if` - takes boolean expression, `default` - takes no expression and applied only if no other scopes are applied in chain. To their scopes the same rules are applied as for `function` scope. `default` scope modifier cannot be grouped. 
5. Above modifiers can be grouped. Group modifiers are applied to the same scope. 
6. At the same time can be read only one of the grouped scope modifiers above.
```
@onlyUp
class
  @params
    x = 10
  @public
    @let
      y = x - 10

    @fun
      test: void
        switch y
          case 1
          case 2
          case 3
          if y > 7
            print(y)
          match /w/i
            print(y - 6)
          default
            print(`default`)

        switch 0
          case 0
            print(0)
          default
            print(1)
```
- `while` scope modifier - modify current scope and apply following rules:
1. Should take 1 - 3 expressions.
2. if 1 expression is taken, it is considered as `condition`.
3. if 2 expressions are taken, first is considered as `declaration` with let access, second as `condition`.
4. if 3 expressions are taken, first is considered as `declaration` with let access, second as `condition`, third as `assignment`.
5. Inside this scope all `fun` modifiers are available.
6. All fields have `private` access.
7. All expression separated by comma.
8. Scope is read everytime `condition` return true.
9. This scope is loop.
```
@onlyUp
class
  @params
    x = 10
  @public
    @let
      y = x - 10

    @fun
      test: void
        while y < 10
          y++
          print(y)

        while i = 0, i < 10
          i++
          print(i)

        while i = 0, i < 10, i++
          print(i)

        while i = 0, i < 10, i++
          if i < 5
            continue
          if i >= 9
            break
          print(i)

        while true
          print(`first infinity loop`)
          break

        while true
          print(`second infinity loop`)
          =>
```

# 0.2.0.
## new changes:
- Class params can contain `public`, `protected` and `let` variables.
- Functions (Callable variables) can accept named arguments.
```
@onlyUp
class
  @fun
    getString: string
      @params
        x: integer
        y: integer
        z = 777
        w = `Good boy!`

      => `{x} + {y} = {z}, {w}`

    testPrint: void
      @params
        x: integer
        y: integer
        z = 777
        w = `Good boy!`

      print(`{x} + {y} = {z}, {w}`)

  @public
    @fun
      test: void
        @read
          string = getString(
            y = 111
            x = 666

          z = 222

        print(string)
        testPrint(
          y = 111
          x = 111
          z
```

# 0.3.0.
## new changes:
- Added new import scope modifier: `@local` - import allowed only in current directory.
- Added new import scope modifier: `@invisible` - import allowed nowhere.

# 0.4.0.
## new changes:
- Added new native class `Date`.
- Static method `Date.now` - current date as ms.
- Static method `Date.toISOString` - converts ms to iso string.
- public field `date.ms` - keeps date as ms.

# 0.5.0.
## new changes:
- Added new class scope modifier: `@template` - type template arguments for class, all data in class can use provided type. But its usage restriction is equal to `unknwon` type.
- All template arguments required yet.
- Template argument must start with `_` and be in PascalCase.
- While class instantiating, all template arguments (types) must be provided in `<` (open template arguments calling symbol) and `>` (close template arguments calling symbol), before arguments calling `()`. If there is no template argument for class instance, you must not use `<>` symbols.
```
@onlyUp
class
  @template
    _PrintedValue
    _T
  @params
    a: _PrintedValue
    b: _PrintedValue

  @public
    @fun
      test: void
        print(a)
        print(b)
        
...

templateClass = TemplateClass<integer, integer>(1, 2)
```

# 0.6.0.
## new changes:
- Added new native class `Vector`.
- Fixed incorrect work of `get` variables.
- Fixed incorrect work of templates arguments.
- Named arguments now works with template arguments.
```
@onlyUp
class
  @public
    @fun
      test: void
        @read
          vector = Vector<integer>(0, 1, 2, 3, 4)
          first = vector.get(0)
          print(first)
          vector.set(0, -1)
          print(vector.get(0))
          print(vector.size)

        print(vector)
        print(first)
```

# 0.7.0.
## new changes:
- Added new native class `Map`.
- Fixed incorrect arguments placement of `get` of `Vector` class.
```
@onlyUp
class
  @public
    @fun
      test: void
        @read
          map = Map<string, integer>()
          map.set(`theater`, 0)
          map.set(`office`, 1)
          map.set(`skyscraper`, 2)
          first = map.get(`theater`)
          print(first)
          map.set(`theater`, -1)
          print(map.get(`theater`))

        print(map)
        print(first)
```

# 0.8.0.
## new changes:
- Added new scope modifier: `for in` - a loop by all elements and keys in Map, Vector or string.
- Fixed internal name conflicts.
```
@onlyUp
class
  @params
    x = 10
  @public
    @let
      y = x - 10

    @fun
      test: void
        for value in x
          print(value)
          for value, key in y
            print(key)
            print(value)

        for char, index in `for in`
          print(char)
          print(index)

        for char in `for in`
          print(char)

        @read
          v = Vector<string>(`f`, `o, `r, ` `, `i`, `n`)
          m = Map<string, integer>()
          m.set(`H`, -1)
          m.set(`i`, 1)

        for char, index in v
          print(char)
          print(index)

        for char in v
          print(char)

        for number, char in m
          print(char)
          print(index)

        for number in m
          print(number)
```

# 0.9.0.
## new changes:
- Added new function modifier: `@async` - changes function return type to `Future`, it allows to run code asynchronously.
- Added new unary operator `~` (await): force a program to run `Future` term synchronously. It can be used even inside synchronous functions.
- Changed `toString` unary operator symbol from `~` to `@`.
```
@onlyUp
class
  @fun
    @async
    testIntegerFuture: Future<integer>
      => 777

    @async
    testVoidFuture: Future<void>
      @read
        value = ~testIntegerFuture()
      print(value)

  @public
    @fun
      test: void
        print(Date.now())
        testVoidFuture()
        print(Date.now())
```

# 0.10.0.
## new changes:
- Added new native class `ErrorMessage`.
- Added new operator `==>` (raise): it raises instance of ErrorMessage class until nearest `try` scope or ends current process.
- Added new scope modifier: `try` - preventing for process to collapse. Can only be used with `catch` scope modifier.
- Added new scope modifier: `catch` - preventing for process to collapse, catches the instance of ErrorMessage. Can only be used with `try` scope modifier.
- Now named arguments syntax works with `=>` and `==>` operators.
- Added validation for correct usage of named arguments.
- Now all compilation errors have unified correct view with provided line number of error.
```
@onlyUp
class
  @fun
    returnShortcutDate: Date
      @read
        ms = 777
      => Date(
        ms

    throwShortcutError: void
      ==> MessageError(
        message = `Throw error test.`

    throwError: void
      ==> MessageError(`Throw error test.`)

  @public
    @fun
      test: void
        # Test compilation error: Variable is not defined: error.
        # print(error)
        @let
          date = Date(0)

        try
          throwShortcutError()
        catch e
          print(e.message)

        try
          date = returnShortcutDate()
          throwError()
        catch e
          print(e.message)

        print(date.ms)
```

# 0.11.0.
## new changes:
- Added new class modifier `@static`. If it's applied, all properties and methods of the class are now static. Apply restrictions to this class: can't be enum, can extend only static classes, can't be instantiated.
- Fixed incorrect compilation of static properties and methods.
```
@onlyUp
@static
class
  privateVariable = `Static private variable`

  @public
    publicVariable = `Static public variable`

    @fun
      test: void
        for i in 5
          @read
            variable = i

          if i == 3
            print(`Static method {variable}`)

        print(`Static method`)
        print(privateVariable)
        print(publicVariable)
```

# 0.12.0.
## new changes:
- Added new class modifier `@virtual`. If it's applied, all properties and methods of the class are now virtual. Apply restrictions to this class: can't be another subtype (enum, static), can extend only virtual classes, can't be instantiated. All properties of virtual class have only type but not implementation.
- Added new class scope modifier `@implements`. If it's applied, all properties of implemented class must be implemented.
- Improved class scope modifiers compilation validation.
```
@local
@virtual
class
  @public
    a: float
    b: float

    @fun
      init: void
      destroy: void
      test: void
      
-------------------
      
@import
  .VirtualClass

@onlyUp
class
  @implements
    VirtualClass
  @public
    a = 1.0
    b = 1.0

    @fun
      init: void
        print(`init`)
      destroy: void
        print(`destroy`)
      test: void
        print(a)
        print(b)
        print(`test`)
```

# 0.13.0.
## new changes:
- Added the possibility to pass a function inside a function of level 1. Passing a function as a parameter inside a class or a function as a function parameter is forbidden.
```
@onlyUp
class
  c = 1

  @public
    @fun
      sum: integer
        @params
          a: integer
          b: integer

        => a + b

      noParamsFunction: void
        print(`This function has no params`)

      testNoParams: void
        @params
          @fun
            noParamsFunction: void

        noParamsFunction()

      testSum: integer
        @params
          a: integer
          b: integer
          @fun
            sum: integer
              @params
                a: integer
                b: integer

        => sum(a, b)

      test: void
        testNoParams(noParamsFunction)
        print(testSum(1, c, sum))
```

# 0.14.0.
## new changes:
- Added new native class `FS`. It supports handling text files.
- Fixed incorrect compilation of MessageError class.
- Fixed incorrect handling of function which returns Future<void>.
```
@onlyUp
class
  @fun
    testRead: string
      @read
        path = `/users/Jane/test.txt`
      @let
        string = ``

      if FS.exists(path)
        string = ~FS.read(path)

      => string

    testWrite: boolean
      @params
        text: string
      @read
        path = `/users/Jane/test.txt`

      if FS.exists(path)
        ~FS.write(path, text, true)
        => true

      => false

  @public
    @fun
      test: void
        print(Date.now())
        print(testRead())
        if testWrite(`new Text`)
          print(testRead())
        print(Date.now())
```

# 0.15.0.
## new changes:
- Added new native class `Server`. For now, it supports text response to whoever requests it.
```
@onlyUp
class
  @public
    @fun
      test: void
        @read
          server = Server(2999)
        ~server.run(`Response from server!`)
```

# 0.15.1.
## bugfix:
- fixed incorrect working of `@let` and `@react` variables.
- added ./examples/reactivity.

# 0.15.2.
## bugfix:
- fixed incorrect working of `@enum` class.
- added ./examples/use-enum.

# 0.15.3.
## bugfix:
- fixed incorrect working of `@static` class.
- fixed incorrect working of `@static` fields.
- fixed incorrect working of `@virtual` class.
- added ./examples/use-static.
- added ./examples/use-virtual.

# 0.15.4.
## bugfix:
- fixed incorrect working of `Future` class.
- added ./examples/file-stream.

# 0.15.5.
## bugfix:
- fixed incorrect handling of `Future` calling.
- added ./examples/run-server

# 0.15.6.
## bugfix:
- fixed incorrect working of `@extends` modifier.
- added ./examples/use-inheritance

# 0.15.7.
## bugfix:
- fixed incorrect parsing of string with '=' symbol.
- added ./examples/pass-function-as-parameter
- added ./examples/library-conflict
- added ./examples/self-call

# 0.15.8.
## bugfix:
- fixed incorrect string parsing.
- fixed internal language name conflicts.
- added ./examples/use-template

# 0.15.9.
## bugfix:
- fixed incorrect working of `Date` class.
- added ./examples/date

# 0.15.10.
## bugfix:
- fixed incorrect working of `Future` class in case of function calling.
- added ./examples/handling-error
- added ./examples/use-async

# 0.15.11.
## bugfix:
- fixed incorrect working of `!!` and `+` operators.
- added ./examples/vector
- added ./examples/type-conversion

# 0.15.12.
## bugfix:
- fixed incorrect working of `search` native function.
- added ./examples/regular-expression
