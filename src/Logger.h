#pragma once

#include <string>

namespace Logg {

    // This enum is used to easily print log messages with a specified level
    enum class LogLevel {
        Debug,
        Info,
        Warn,
        Error,
        Fatal
    };

    // A Logger object has a name and can output many types of messages
    class Logger {

    public:

        // Raw name of this logger
        const std::string& Name;

        // Construct a new Logger with a name
        Logger(const std::string& name);

        // Destroy this Logger
        ~Logger();

        // Disable the copy constructor
        Logger(const Logger& other) = delete;

        // Disable copy assignment
        Logger& operator=(const Logger& other) = delete;

        /* Variadic Logging functions */

        // Print a debug log message
        template<typename... Args>
        void Debug(const Args&... args) const {
#ifdef NDEBUG
            LogMessage(LogLevel::Debug, MergeStrings({ ToString(args) ... }));
#endif
        }

        // Print an info log message
        template<typename... Args>
        void Info(const Args&... args) const {
            LogMessage(LogLevel::Info, MergeStrings({ ToString(args) ... }));
        }

        // Print a warning log message
        template<typename... Args>
        void Warn(const Args&... args) const {
            LogMessage(LogLevel::Warn, MergeStrings({ ToString(args) ... }));
        }

        // Print an error log message
        template<typename... Args>
        void Error(const Args&... args) const {
            LogMessage(LogLevel::Error, MergeStrings({ ToString(args) ... }));
        }

        // Print a fatal log message that stops program execution
        template<typename... Args>
        void Fatal(const Args&... args) const {
            LogMessage(LogLevel::Fatal, MergeStrings({ ToString(args) ... }));
        }

        // Print a log message with a specified LogLevel
        template<typename... Args>
        void LogMessage(LogLevel level, const Args&... args) const {

            auto stamp = GetTimestamp();

            std::string levelLabel;
            switch (level) {
            case LogLevel::Debug:
                levelLabel = " [DEBUG]";
                break;
            case LogLevel::Info:
                levelLabel = " [INFO]";
                break;
            case LogLevel::Warn:
                levelLabel = " [WARN]";
                break;
            case LogLevel::Error:
                levelLabel = " [ERROR]";
                break;
            case LogLevel::Fatal:
                levelLabel = " [FATAL]";
                break;
            }

            std::cout << stamp
                << nameLabel
                << levelLabel
                << " " << MergeStrings({ ToString(args) ... })
                << std::endl;
        }

        /* Single String Logging functions */

        // Print a debug log message
        void Debug(const std::string& message) const;

        // Print an info log message
        void Info(const std::string& message) const;

        // Print a warning log message
        void Warn(const std::string& message) const;

        // Print an error log message
        void Error(const std::string& message) const;

        // Print a fatal log message that stops program execution
        void Fatal(const std::string& message) const;

        // Print a log message with a specified LogLevel
        void LogMessage(LogLevel level, const std::string& message) const;

    private:

        // Slightly formatted version of this logger's name
        std::string nameLabel;

        // Get a formatted timestamp
        std::string GetTimestamp() const;

        // Merge a list of strings into one
        std::string MergeStrings(std::initializer_list<std::string> strings) const;

        // Use std::ostringstream to convert any type to a string
        template<typename T>
        std::string ToString(T value) const {
            std::ostringstream stream;
            stream << value;
            return stream.str();
        }

    };

    // A global Logger that can be accessed without making your own
    const Logger GlobalLog("Global Log");

}
