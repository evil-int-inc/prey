# v1.0.0
# v1.1.0
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
# v1.2.0
## new changes:
- Added new import scope modifier: `@local` - import allowed only in current directory.
- Added new import scope modifier: `@invisible` - import allowed nowhere.
# v1.3.0
## new changes:
- Added new native class `Date`.
- Static method `Date.now` - current date as ms.
- Static method `Date.toISOString` - converts ms to iso string.
- public field `date.ms` - keeps date as ms.
# v1.4.0
## new changes:
- Added new class scope modifier: `@template` - type template arguments for class, all data in class can use provided type. But its usage restriction is equal to `unknwon` type.
- All template arguments required yet.
- Template argument must start with `_` and be in PascalCase.
- While class instantiating, all template arguments (types) must be provided in `<` (open template arguments calling symbol) and `>` (close template arguments calling symbol), before arguments calling `()`. If there is not template argument for class instance, you must not use `<>` symbols.
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
# v1.5.0
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
# v1.6.0
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
# v1.7.0
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
# v1.8.0
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
# v1.9.0
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
# v1.10.0
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
# v1.11.0
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
