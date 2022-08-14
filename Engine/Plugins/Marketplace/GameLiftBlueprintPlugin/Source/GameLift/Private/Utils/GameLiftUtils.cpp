/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#include "Utils/GameLiftUtils.h"
#include "Internationalization/Regex.h"

EGameLiftARNType UGameLiftUtils::IdentifyGameLiftARNType(const FString &awsResourceName) {
	{
		FRegexPattern FleetIdPattern = FRegexPattern(
			FString("^fleet-[a-zA-Z0-9]{8}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{12}$"));

		FRegexMatcher FleetIdMatcher(FleetIdPattern, awsResourceName);

		if (FleetIdMatcher.FindNext()) {
			return EGameLiftARNType::Fleet_Id;
		}
	}
    
	{
		FRegexPattern AliasIdPattern = FRegexPattern(
			FString("^alias-[a-zA-Z0-9]{8}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{12}$"));

		FRegexMatcher AliasIdMatcher(AliasIdPattern, awsResourceName);

		if (AliasIdMatcher.FindNext()) {
			return EGameLiftARNType::Alias_Id;
		}
	}
    
	{
		FRegexPattern GameSessionIdPattern = FRegexPattern(
			FString("^arn:aws:gamelift:(?:local|us\\-east\\-2|us\\-east\\-1|us\\-west\\-1|us\\-west\\-2|ap\\-south\\-1|ap\\-northeast\\-2|ap\\-southeast\\-1|ap\\-southeast\\-2|ap\\-northeast\\-1|ca\\-central\\-1|eu\\-central\\-1|eu\\-west\\-1|eu\\-west\\-2|sa\\-east\\-1)::gamesession\\/fleet-[a-zA-Z0-9]{8}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{4}-[a-zA-Z0-9]{12}\\/.*?$"));

		FRegexMatcher GameSessionIdMatcher(GameSessionIdPattern, awsResourceName);

		if (GameSessionIdMatcher.FindNext()) {
			return EGameLiftARNType::GameSession_Id;
		}
	}

    return EGameLiftARNType::UNKNOWN;
}
