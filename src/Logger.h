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

        // A global Logger that can be accessed without making your own
        static const Logger GlobalLog;

        // Raw name of this logger
        const std::string& Name;

        // Construct a new Logger with a name
        Logger(const std::string& name);

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

    };

}
