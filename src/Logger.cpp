#include "Logger.h"

#include <iostream>
#include <sstream>
#include <iomanip>

namespace Logg {

    const Logger Logger::GlobalLog("Global Log");

    Logger::Logger(const std::string& name) : Name(name) {
        // Log that this Logger has been created
        nameLabel = " [" + name + "]";
        Info("Created logger: " + name);
    }

    void Logger::Debug(const std::ostringstream& stream) const {
#ifdef NDEBUG
        LogMessage(LogLevel::Debug, stream);
#endif
    }

    void Logger::Info(const std::ostringstream& stream) const {
        LogMessage(LogLevel::Info, stream);
    }

    void Logger::Warn(const std::ostringstream& stream) const {
        LogMessage(LogLevel::Warn, stream);
    }

    void Logger::Error(const std::ostringstream& stream) const {
        LogMessage(LogLevel::Error, stream);
    }

    void Logger::Fatal(const std::ostringstream& stream) const {
        LogMessage(LogLevel::Fatal, stream);
        exit(1);
    }

    void Logger::LogMessage(LogLevel level, const std::ostringstream& stream) const {
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
            << " " << stream.str()
            << std::endl;
    }

    void Logger::Debug(const std::string& message) const {
#ifdef NDEBUG
        LogMessage(LogLevel::Debug, message);
#endif
    }

    void Logger::Info(const std::string& message) const {
        LogMessage(LogLevel::Info, message);
    }

    void Logger::Warn(const std::string& message) const {
        LogMessage(LogLevel::Warn, message);
    }

    void Logger::Error(const std::string& message) const {
        LogMessage(LogLevel::Error, message);
    }

    void Logger::Fatal(const std::string& message) const {
        LogMessage(LogLevel::Fatal, message);
        exit(1);
    }

    void Logger::LogMessage(LogLevel level, const std::string& message) const {
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
            << " " << message
            << std::endl;
    }

    std::string Logger::GetTimestamp() const {
        auto now = std::time(nullptr);
        auto local = *std::localtime(&now);

        // Using a stringstream is probably not ideal
        std::stringstream stamp;
        stamp << std::put_time(&local, "[%F %T %Z]");

        return stamp.str();
    }

}
