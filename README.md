# Logg

This is a simple C++ Logger library

## Usage

Create a Logger object with `Logg::Logger MyLogger("MyLoggerName");`

Then print some messages with the functions `Debug()`, `Info()`, `Warn()`, `Error()`, or `Fatal()`

You can also use `LogMessage(LogLevel::Info, message);` as a different way to output messages

Note that:

`Logger::Debug()` outputs its message only if the `DEBUG` macro is defined

`Logger::Fatal()` prints a fatal message, then terminates the program with `exit(1)`

## Example

```C++
#include "Logger.h"

int main() {
    Logg::Logger MyLogger("Test Log");
    
    MyLogger.Debug("This is only visible if NDEBUG is defined!");
    
    MyLogger.Info("This is an standard message");
    
    MyLogger.Fatal("A fatal error has occurred!"); // Terminates the program
    
    // Note: program execution will not reach this point.
    MyLogger.Warn("Not quite an error, but more important than an Info message");
}
```

This produces the output when compiled with a Release configuration:

```
[2020-12-20 22:23:14 CST] [Test Log] [INFO] Created logger: Test Log
[2020-12-20 22:23:14 CST] [Test Log] [INFO] This is an standard message
[2020-12-20 22:23:14 CST] [Test Log] [FATAL] A fatal error has occurred!
```

## License
[MIT](https://choosealicense.com/licenses/mit)