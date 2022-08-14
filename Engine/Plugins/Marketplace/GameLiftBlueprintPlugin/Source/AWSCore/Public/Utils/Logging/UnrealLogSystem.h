/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, Sept 2020
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_CORE
#include "aws/core/utils/logging/LogSystemInterface.h"
#include "aws/core/utils/logging/LogLevel.h"
#endif

#if WITH_CORE
class AWSCORE_API UnrealLogSystem : public Aws::Utils::Logging::LogSystemInterface
{
public:
    UnrealLogSystem(Aws::Utils::Logging::LogLevel logLevel) :
        m_logLevel(logLevel)
    {}
    
    virtual ~UnrealLogSystem() {}
    
    /**
     * Gets the currently configured log level.
     */
    virtual Aws::Utils::Logging::LogLevel GetLogLevel(void) const override { return m_logLevel; }
    /**
     * Set a new log level. This has the immediate effect of changing the log output to the new level.
     */
    void SetLogLevel(Aws::Utils::Logging::LogLevel logLevel) { m_logLevel.store(logLevel); }
    
    /**
     * Does a printf style output to ProcessFormattedStatement. Don't use this, it's unsafe. See LogStream
     */
    virtual void Log(Aws::Utils::Logging::LogLevel logLevel, const char* tag, const char* formatStr, ...) override;

    /**
     * Writes the stream to ProcessFormattedStatement.
     */
    virtual void LogStream(Aws::Utils::Logging::LogLevel logLevel, const char* tag, const Aws::OStringStream &messageStream) override;

    /**
     * Flushes buffered messages to stdout.
     */
    void Flush() override;
    
private:
    std::atomic<Aws::Utils::Logging::LogLevel> m_logLevel;
};
#endif
