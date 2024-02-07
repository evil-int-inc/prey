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
- Added new import scope modifier: `@local` - import allowed only in current directory
- Added new import scope modifier: `@invisible` - import allowed nowhere
- # v1.3.0
## new changes:
- Added new native class `Date`:
- Static method `Date.now` - current date as ms.
- Static method `Date.toISOString` - converts ms to iso string.
- public field `date.ms` - keeps date as ms.