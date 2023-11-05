/**
 * @file logger.h
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @brief Singleton Logger Class for logging data to output file and console
 * @version 0.1
 * @date 2023-11-05
 * @copyright Copyright (c) 2023
 */

#pragma once

#include <string>
#include <fstream>
#include <mutex>

/**
 * @class Logger
 * @brief Class for logging data to output file and console
 */
class Logger
{
public:
    enum class Level
    {
        INFO,
        WARNING,
        ERROR,
        FATAL
    };

    // Singleton access
    /**
     * @brief Gets the active instance of the Logger class
     *
     * @return Logger& The active instance of the Logger class
     */
    inline static Logger &getInstance()
    {
        static Logger instance;
        return instance;
    }

    // Deleted methods to prevent copying
    Logger(Logger const &) = delete;
    Logger &operator=(const Logger &) = delete;
    Logger(Logger &&) = delete;
    Logger &operator=(Logger &&) = delete;

    // Configuration Methods
    Logger &setLogLevel(Level level);
    Logger &setConsoleOutput(bool output);
    Logger &setFileOutput(bool output);
    Logger &setOutputFile(const std::string &filepath);

    // Logging Methods
    void log(Level level, const std::string &message,
             const std::string &filename, int line);
    void flush();

private:
    std::ofstream m_file;
    std::string m_outputFilepath;
    bool m_consoleOutput = true;
    bool m_fileOutput = true;
    std::mutex m_mutex;
    Level m_logLevel = Level::INFO;

    // Private constructor
    Logger();

    // Private Destructor
    ~Logger();

    // Utility Methods
    std::string formatMessage(Level level, const std::string &message,
                              const std::string &filename, int line);
    std::string getColor(Level level);
    std::string levelToString(Level level);
    void openLogFile();
    void handleFileError(const std::string &message);

    // ANSI Escape Codes
    const std::string ANSI_RESET = "\033[0m";
    const std::string ANSI_BOLD = "\033[1m";
    const std::string ANSI_RED = "\033[31m";
    const std::string ANSI_YELLOW = "\033[33m";
    const std::string ANSI_BLUE = "\033[34m";
    const std::string ANSI_GREEN = "\033[32m";
};

// Macros for logging
/**
 * @brief Logs a message to the console and/or log file
 *
 * @param[in] level The log level of the message
 * @param[in] message The message to log
 *
 * @note The __FILE__ and __LINE__ macros are automatically passed to the
 *      Logger::log() method
 *
 * @note Usage: LOG(Logger::Level::INFO, "This is a message");
 */
#define LOG(level, message) \
    Logger::getInstance().log(level, message, __FILE__, __LINE__)

/**
 * @brief Logs an informational message to the console and/or log file
 *
 * @param[in] message The message to log
 *
 * @note The __FILE__ and __LINE__ macros are automatically passed to the
 *     Logger::log() method
 *
 * @note Usage: LOG_INFO("This is an informational message");
 */
#define LOG_INFO(message) \
    Logger::getInstance().log(Logger::Level::INFO, message, __FILE__, __LINE__)

/**
 * @brief Logs a warning message to the console and/or log file
 *
 * @param[in] message The message to log
 *
 * @note The __FILE__ and __LINE__ macros are automatically passed to the
 *    Logger::log() method
 *
 * @note Usage: LOG_WARNING("This is a warning message");
 */
#define LOG_WARNING(message) \
    Logger::getInstance().log(Logger::Level::WARNING, message, __FILE__, __LINE__)

/**
 * @brief Logs an error message to the console and/or log file
 *
 * @param[in] message The message to log
 *
 * @note The __FILE__ and __LINE__ macros are automatically passed to the
 *   Logger::log() method
 *
 * @note Usage: LOG_ERROR("This is an error message");
 */
#define LOG_ERROR(message) \
    Logger::getInstance().log(Logger::Level::ERROR, message, __FILE__, __LINE__)

/**
 * @brief Logs a fatal error message to the console and/or log file
 *
 * @param[in] message The message to log
 *
 * @note The __FILE__ and __LINE__ macros are automatically passed to the
 *  Logger::log() method
 *
 * @note Usage: LOG_FATAL("This is a fatal error message");
 */
#define LOG_FATAL(message) \
    Logger::getInstance().log(Logger::Level::FATAL, message, __FILE__, __LINE__)
