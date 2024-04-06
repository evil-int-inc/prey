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
# v1.6.0
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