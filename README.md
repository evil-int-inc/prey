# To run programs do followings:
- install last version of g++
- run `sh <path-to-evil.sh-script> <path-to-source-code>`
- example: `sh evil.sh ./examples/hello-world`

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

# Language types
- integer
- float
- boolean
- string
- RE (Regular Expression)
- <ClassName\>

# Languages features (v1.1.0)
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