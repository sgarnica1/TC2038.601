/**
 * @file logger.cpp
 * @author Alejandra Cabrera
 * @author Carlos Salguero
 * @author Sergio Garnica
 * @brief Singleton Logger Class for logging data to output file and console
 * @version 0.1
 * @date 2023-11-05
 * @copyright Copyright (c) 2023
 */
#include <iostream>
#include <fstream>
#include <sstream>
#include <chrono>
#include <iomanip>
#include <filesystem>
#include <system_error>
#include <cstring>

#include "logger.h"

// Constructor
/**
 * @brief Construct a new Logger:: Logger object
 *
 */
Logger::Logger()
{
    m_outputFilepath = "../../../logs/log.txt";
    openLogFile();
}

// Destructor
/**
 * @brief Destroy the Logger:: Logger object
 *
 */
Logger::~Logger()
{
    if (m_file.is_open())
    {
        m_file.flush();
        m_file.close();
    }

    flush();
}

// Configuration Methods
/**
 * @brief Sets the log level
 *
 * @param[in] level The log level to set
 * @return Logger& A reference to the Logger object
 */
Logger &Logger::setLogLevel(Level level)
{
    m_logLevel = level;
    return *this;
}

/**
 * @brief Sets whether or not to output to the console
 *
 * @param[in] output Whether or not to output to the console
 * @return Logger& A reference to the Logger object
 */
Logger &Logger::setConsoleOutput(bool output)
{
    m_consoleOutput = output;
    return *this;
}

/**
 * @brief Sets whether or not to output to the log file
 *
 * @param[in] output Whether or not to output to the log file
 * @return Logger& A reference to the Logger object
 */
Logger &Logger::setFileOutput(bool output)
{
    m_fileOutput = output;
    return *this;
}

/**
 * @brief Sets the output file path
 *
 * @param[in] filepath The output file path
 * @return Logger& A reference to the Logger object
 */
Logger &Logger::setOutputFile(const std::string &filepath)
{
    std::lock_guard<std::mutex> lock(m_mutex);

    m_outputFilepath = filepath;
    openLogFile();

    return *this;
}

// Logging Methods
/**
 * @brief Logs a message to the console and/or log file
 *
 * @param[in] level The log level of the message
 * @param[in] message The message to log
 * @param[in] filename The name of the file the message is logged from
 * @param[in] line The line number the message is logged from
 */
void Logger::log(Level level, const std::string &message,
                 const std::string &filename, int line)
{
    if (level < m_logLevel)
        return;

    std::lock_guard<std::mutex> lock(m_mutex);
    std::string formattedMessage = formatMessage(level, message,
                                                 filename, line);

    if (m_consoleOutput)
        std::cout << getColor(level) << formattedMessage
                  << ANSI_RESET << std::endl;

    if (m_fileOutput)
    {
        if (!m_file.is_open())
            openLogFile();

        if (m_file.is_open())

            m_file << formattedMessage << std::endl;

        else
            handleFileError("Error writing to log file");
    }
}

/**
 * @brief Flushes the log file
 *
 */
void Logger::flush()
{
    std::lock_guard<std::mutex> lock(m_mutex);

    if (m_file.is_open())
        m_file.flush();
}

// Utility Methods
/**
 * @brief Formats the log message
 *
 * @param[in] level The log level of the message
 * @param[in] message The message to log
 * @param[in] filename The name of the file the message is logged from
 * @param[in] line The line number the message is logged from
 * @return std::string The formatted log message
 */
std::string Logger::formatMessage(Level level, const std::string &message,
                                  const std::string &filename, int line)
{
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);

    std::stringstream ss;
    ss << "[" << std::put_time(&now_tm, "%Y-%m-%d %H:%M:%S") << "] "
       << "[" << levelToString(level) << "] "
       << "[" << filename << ":" << line << "] "
       << message;

    return ss.str();
}

/**
 * @brief Returns the color of the log
 *
 * @param[in] level The level of the log
 * @return std::string The color of the log
 */
std::string Logger::getColor(Level level)
{
    switch (level)
    {
    case Level::INFO:
        return ANSI_GREEN;

    case Level::WARNING:
        return ANSI_YELLOW;

    case Level::ERROR:
        return ANSI_RED;

    case Level::FATAL:
        return ANSI_BOLD + ANSI_RED;

    default:
        return ANSI_RESET;
    }
}

/**
 * @brief Converts the log level to a string
 *
 * @param[in] level The log level to convert
 * @return std::string The string representation of the log level
 */
std::string Logger::levelToString(Level level)
{
    switch (level)
    {
    case Level::INFO:
        return "INFO";

    case Level::WARNING:
        return "WARNING";

    case Level::ERROR:
        return "ERROR";

    case Level::FATAL:
        return "FATAL";

    default:
        return "UNKNOWN";
    }
}

/**
 * @brief Opens the log file
 *
 */
void Logger::openLogFile()
{
    std::filesystem::path logPath(m_outputFilepath);
    std::filesystem::path logDir = logPath.parent_path();

    std::error_code ec;

    if (!std::filesystem::exists(logDir) &&
        !std::filesystem::create_directories(logDir, ec))
    {
        std::cerr << "Failed to create log directory: "
                  << ec.message() << std::endl;

        return;
    }

    m_file.open(m_outputFilepath, std::ios::out | std::ios::app);
    if (!m_file.is_open())
    {
        std::cerr << "Failed to open log file: "
                  << std::strerror(errno) << std::endl;
    }
}

/**
 * @brief Handles errors when writing to the log file
 *
 * @param[in] message The error message
 */
void Logger::handleFileError(const std::string &message)
{
    std::string formattedMessage = formatMessage(Level::FATAL, message,
                                                 __FILE__, __LINE__);

    std::cerr << formattedMessage << std::endl;

    m_consoleOutput = true;
    m_fileOutput = false;
    m_file.close();
}