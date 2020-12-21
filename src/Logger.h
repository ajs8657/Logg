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

        // Print a debug log message
        void Debug(const std::string& message);

        // Print an info log message
        void Info(const std::string& message);

        // Print a warning log message
        void Warn(const std::string& message);

        // Print an error log message
        void Error(const std::string& message);

        // Print a fatal log message that stops program execution
        void Fatal(const std::string& message);

        // Print a log message with a specified LogLevel
        void LogMessage(LogLevel level, const std::string& message);

    private:

        // Slightly formatted version of this logger's name
        std::string nameLabel;

        // Get a formatted timestamp
        std::string GetTimestamp();

    };

}
