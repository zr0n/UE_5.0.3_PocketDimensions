/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, Sept 2020
 */

#include "Utils/Logging/UnrealLogSystem.h"

#include "AWSCoreGlobals.h"

#if WITH_CORE

#include "aws/core/utils/Array.h"

#include <fstream>
#include <cstdarg>
#include <stdio.h>
#include <thread>

void UnrealLogSystem::Log(Aws::Utils::Logging::LogLevel logLevel, const char* tag, const char* formatStr, ...)
{
    Aws::StringStream ss;
    ss << tag << " [" << std::this_thread::get_id() << "] ";

    std::va_list args;
    va_start(args, formatStr);

    va_list tmp_args; //unfortunately you cannot consume a va_list twice
    va_copy(tmp_args, args); //so we have to copy it
    #ifdef WIN32
        const int requiredLength = _vscprintf(formatStr, tmp_args) + 1;
    #else
        const int requiredLength = vsnprintf(nullptr, 0, formatStr, tmp_args) + 1;
    #endif
    va_end(tmp_args);

    Aws::Utils::Array<char> outputBuff(requiredLength);
    #ifdef WIN32
        vsnprintf_s(outputBuff.GetUnderlyingData(), requiredLength, _TRUNCATE, formatStr, args);
    #else
        vsnprintf(outputBuff.GetUnderlyingData(), requiredLength, formatStr, args);
    #endif // WIN32

    ss << outputBuff.GetUnderlyingData() << std::endl;
  
    switch(logLevel) {
        case Aws::Utils::Logging::LogLevel::Off:
            break;
        case Aws::Utils::Logging::LogLevel::Fatal:
            LOG_AWSCORE_ERROR(UTF8_TO_TCHAR(ss.str().c_str()));
            break;
        case Aws::Utils::Logging::LogLevel::Error:
            LOG_AWSCORE_ERROR(UTF8_TO_TCHAR(ss.str().c_str()));
            break;
        case Aws::Utils::Logging::LogLevel::Warn:
            LOG_AWSCORE_WARNING(UTF8_TO_TCHAR(ss.str().c_str()));
            break;
        case Aws::Utils::Logging::LogLevel::Info:
            LOG_AWSCORE_NORMAL(UTF8_TO_TCHAR(ss.str().c_str()));
            break;
        case Aws::Utils::Logging::LogLevel::Debug:
            LOG_AWSCORE_VERBOSE(UTF8_TO_TCHAR(ss.str().c_str()));
            break;
        case Aws::Utils::Logging::LogLevel::Trace:
            LOG_AWSCORE_VERYVERBOSE(UTF8_TO_TCHAR(ss.str().c_str()));
            break;
    }

    va_end(args);
}

void UnrealLogSystem::LogStream(Aws::Utils::Logging::LogLevel logLevel, const char* tag, const Aws::OStringStream &message_stream)
{
    Aws::StringStream ss;
    ss << tag << " [" << std::this_thread::get_id() << "] ";
    
    switch(logLevel) {
        case Aws::Utils::Logging::LogLevel::Off:
            break;
        case Aws::Utils::Logging::LogLevel::Fatal:
            LOG_AWSCORE_ERROR(UTF8_TO_TCHAR((ss.str() + message_stream.str() + "\n").c_str()));
            break;
        case Aws::Utils::Logging::LogLevel::Error:
            LOG_AWSCORE_ERROR(UTF8_TO_TCHAR((ss.str() + message_stream.str() + "\n").c_str()));
            break;
        case Aws::Utils::Logging::LogLevel::Warn:
            LOG_AWSCORE_WARNING(UTF8_TO_TCHAR((ss.str() + message_stream.str() + "\n").c_str()));
            break;
        case Aws::Utils::Logging::LogLevel::Info:
            LOG_AWSCORE_NORMAL(UTF8_TO_TCHAR((ss.str() + message_stream.str() + "\n").c_str()));
            break;
        case Aws::Utils::Logging::LogLevel::Debug:
            LOG_AWSCORE_VERBOSE(UTF8_TO_TCHAR((ss.str() + message_stream.str() + "\n").c_str()));
            break;
        case Aws::Utils::Logging::LogLevel::Trace:
            LOG_AWSCORE_VERYVERBOSE(UTF8_TO_TCHAR((ss.str() + message_stream.str() + "\n").c_str()));
            break;
    }
}

void UnrealLogSystem::Flush() {
}
#endif
