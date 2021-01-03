#include "../include/Logger.h"

#include <iomanip>

namespace Logg {

    Logger::Logger(const std::string& name) : Name(name) {
        // Log that this Logger has been created
        nameLabel = " [" + name + "]";
        Info("Created logger: " + name);
    }

    Logger::~Logger() {
        Info("Destroying logger: " + Name);
    }

    void Logger::Debug(const std::string& message) const {
#ifdef DEBUG
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

    std::string Logger::MergeStrings(std::initializer_list<std::string> strings) const {
        std::string result = "";
        for (std::string s : strings) {
            result += s;
        }
        return result;
    }

}
