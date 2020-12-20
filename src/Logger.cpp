<<<<<<< HEAD
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
        std::cout << stamp
            << " [" << name << "]"
            << " [DEBUG] "
            << message
            << std::endl;
    }

    void Logger::Info(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp
            << " [" << name << "]"
            << " [INFO] "
            << message
            << std::endl;
    }

    void Logger::Warn(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp
            << " [" << name << "]"
            << " [WARN] "
            << message
            << std::endl;
    }

    void Logger::Error(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp
            << " [" << name << "]"
            << " [ERROR] "
            << message
            << std::endl;
    }

    void Logger::Fatal(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp
            << " [" << name << "]"
            << " [FATAL] "
            << message
            << std::endl;
        exit(1);
    }

    std::string Logger::GetTimestamp() {

        auto now = std::time(nullptr);
        auto local = *std::localtime(&now);

        // Using a stringstream is probably not ideal
        std::stringstream stamp;
        stamp << std::put_time(&local, "[%F %T %Z]");

        return stamp.str();

    }

}
=======
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
        std::cout << stamp
            << " [" << name << "] "
            << " [DEBUG] "
            << message
            << std::endl;
    }

    void Logger::Info(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp
            << " [" << name << "] "
            << " [INFO] "
            << message
            << std::endl;
    }

    void Logger::Warn(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp
            << " [" << name << "] "
            << " [WARN] "
            << message
            << std::endl;
    }

    void Logger::Error(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp
            << " [" << name << "] "
            << " [ERROR] "
            << message
            << std::endl;
    }

    void Logger::Fatal(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << stamp
            << " [" << name << "] "
            << " [FATAL] "
            << message
            << std::endl;
        exit(1);
    }

    std::string Logger::GetTimestamp() {

        auto now = std::time(nullptr);
        auto local = *std::localtime(&now);

        // Using a stringstream is probably not ideal
        std::stringstream stamp;
        stamp << std::put_time(&local, "[%F %T %Z]");

        return stamp.str();

    }

}
>>>>>>> 159bcd7d7feb4373d7f7a742198ae87bf3e59d65
