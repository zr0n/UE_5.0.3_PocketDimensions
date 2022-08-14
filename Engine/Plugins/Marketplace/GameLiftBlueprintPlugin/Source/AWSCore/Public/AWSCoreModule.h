/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#pragma once

#include "Modules/ModuleManager.h"

#if WITH_CORE
#include "aws/core/Aws.h"
#include "aws/core/auth/AWSCredentialsProvider.h"
#include "aws/core/client/ClientConfiguration.h"
#include "aws/core/utils/Outcome.h"
#endif

class FAWSCoreModule : public IModuleInterface
{
public:
	void StartupModule();
	void ShutdownModule();

private:
#if WITH_CORE
	Aws::SDKOptions options;
#endif
	static void* AWSCAuthLibraryHandle;
	static void* AWSCCalLibraryHandle;
	static void* AWSCCompressionLibraryHandle;
	static void* AWSCHTTPLibraryHandle;
	static void* AWSCIOLibraryHandle;
	static void* AWSCMQTTLibraryHandle;
	static void* AWSCS3LibraryHandle;
	static void* AWSCCommonLibraryHandle;
	static void* AWSChecksumsLibraryHandle;
	static void* AWSCEventStreamLibraryHandle;
	static void* AWSCRTCPPLibraryHandle;
	static void* AWSCoreLibraryHandle;
	static bool LoadDependency(const FString& Dir, const FString& Name, void*& Handle);
	static void FreeDependency(void*& Handle);
};
