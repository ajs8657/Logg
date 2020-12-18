#pragma once

#include <string>

namespace Logg {

    class Logger {

    public:

        Logger(const std::string& name);

        void Debug(const std::string& message);

        void Info(const std::string& message);

        void Warn(const std::string& message);

        void Error(const std::string& message);

        void Fatal(const std::string& message);

    private:

        const std::string& name;

        std::string GetTimestamp();

    };

}
