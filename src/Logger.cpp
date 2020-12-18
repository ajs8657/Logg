#pragma once

#include "Logger.h"

#include <iostream>
#include <sstream>

namespace Logg {

    // Construct a new Logger with a name
    Logger::Logger(const std::string& name) : name(name) {
        // Log that this Logger has been created
        Info("Created logger: " + name);
    }

    void Logger::Debug(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << "[" << stamp << "] DEBUG:" << message;
    }

    void Logger::Info(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << "[" << stamp << "] INFO:" << message;
    }

    void Logger::Warn(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << "[" << stamp << "] WARNING:" << message;
    }

    void Logger::Error(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << "[" << stamp << "] ERROR:" << message;
    }

    void Logger::Fatal(const std::string& message) {
        auto stamp = GetTimestamp();
        std::cout << "[" << stamp << "] FATAL:" << message;
        exit(1);
    }

    // This sucks
    std::string Logger::GetTimestamp() {

        auto now = time(0);
        auto local = localtime(&now);

        auto year = local->tm_year;
        auto month = local->tm_mon;
        auto day = local->tm_mday;
        auto hour = local->tm_hour;
        auto minute = local->tm_min;
        auto second = local->tm_sec;
        auto zone = local->tm_zone;

        std::stringstream timestamp;
        timestamp << year << "-"
            << month << "-"
            << day << " "
            << hour << ":"
            << minute << ":"
            << second << zone;

        return timestamp.str();

    }

}
