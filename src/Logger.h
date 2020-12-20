#pragma once

#include <string>

namespace Logg {

    enum class LogLevel {
        Debug,
        Info,
        Warn,
        Error,
        Fatal
    };

    class Logger {

    public:

        const std::string& Name;

        Logger(const std::string& name);

        void Debug(const std::string& message);

        void Info(const std::string& message);

        void Warn(const std::string& message);

        void Error(const std::string& message);

        void Fatal(const std::string& message);

        void LogMessage(LogLevel level, const std::string& message);

    private:

        std::string nameLabel;

        std::string GetTimestamp();

    };

}
