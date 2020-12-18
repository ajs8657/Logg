#pragma once

#include "Logger.h"

#include <iostream>
#include <sstream>
#include <iomanip>

namespace Logg {

    // Construct a new Logger with a name
    Logger::Logger(const std::string& name) : name(name) {
        // Log that this Logger has been created
        Info("Created logger: " + name);
    }

    void Logger::Debug(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp << " [DEBUG]" << message;
    }

    void Logger::Info(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp << " [INFO]" << message;
    }

    void Logger::Warn(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp << " [WARNING]" << message;
    }

    void Logger::Error(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp << " [ERROR]" << message;
    }

    void Logger::Fatal(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp << " [FATAL]" << message;
        exit(1);
    }

    std::string Logger::GetTimestamp() {

        auto now = std::time(nullptr);
        auto local = *std::localtime(&now);

        // Using a stringstream is probably not ideal
        std::stringstream stamp;
        stamp << std::put_time(&local, "%F %T %Z");

        return stamp.str();

    }

}
