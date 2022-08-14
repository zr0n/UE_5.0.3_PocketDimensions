/* Copyright (C) Siqi.Wu - All Rights Reserved
 * Written by Siqi.Wu <lion547016@gmail.com>, May 2019
 */

#pragma once

#include "CoreMinimal.h"

#if WITH_CORE

#include "aws/core/client/ClientConfiguration.h"

#endif

#include "Http/AWSHttpTypes.h"

#include "AWSClientConfiguration.generated.h"

UENUM(BlueprintType)
enum class EFollowRedirectsPolicy : uint8 {
    DEFAULT UMETA(DisplayName = "default"),
    ALWAYS UMETA(DisplayName = "always"),
    NEVER UMETA(DisplayName = "never")
};

USTRUCT(BlueprintType)
struct FAWSClientConfiguration {
    GENERATED_USTRUCT_BODY()

    FAWSClientConfiguration() :
            scheme("https"),
            region("us-east-1"),
            useDualStack(false),
            maxConnections(25),
            httpRequestTimeoutMs(0),
            requestTimeoutMs(3000),
            connectTimeoutMs(1000),
            enableTcpKeepAlive(true),
            tcpKeepAliveIntervalMs(30),
            lowSpeedLimit(1),
            proxyScheme("http"),
            proxyPort(0),
            verifySSL(true),
            httpLibOverride(ETransferLibType::DEFAULT_CLIENT),
            followRedirects(EFollowRedirectsPolicy::DEFAULT),
            disableExpectHeader(false),
            enableClockSkewAdjustment(true),
            enableHostPrefixInjection(true),
            enableEndpointDiscovery(false) {
    }

public:

    /**
     * User Agent string user for http calls. This is filled in for you in the constructor. Don't override this unless you have a really good reason.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString userAgent;

    /**
     * Http scheme to use. E.g. Http or Https. Default HTTPS
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString scheme;

    /**
     * AWS Region to use in signing requests. Should be lower case. Default us-east-1
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString region;

    /**
     * Use dual stack endpoint in the endpoint calculation. It is your responsibility to verify that the service supports ipv6 in the region you select.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    bool useDualStack = false;

    /**
     * Max concurrent tcp connections for a single http client to use. Default 25.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    int32 maxConnections;

    /**
     * This is currently only applicable for Curl to set the http request level timeout, including possible dns lookup time, connection establish time, ssl handshake time and actual data transmission time.
     * the corresponding Curl option is CURLOPT_TIMEOUT_MS
     * defaults to 0, no http request level timeout.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    int64 httpRequestTimeoutMs = 0;

    /**
     * Socket read timeouts. Default 3000 ms. This should be more than adequate for most services. However, if you are transfering large amounts of data
     * or are worried about higher latencies, you should set to something that makes more sense for your use case.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    int64 requestTimeoutMs = 0;

    /**
     * Socket connect timeout. Default 1000 ms. Unless you are very far away from your the data center you are talking to. 1000ms is more than sufficient.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    int64 connectTimeoutMs = 0;

    /**
     * Enable TCP keep-alive. Default true;
     * No-op for WinHTTP, WinINet and IXMLHTTPRequest2 client.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    bool enableTcpKeepAlive = false;

    /**
     * Interval to send a keep-alive packet over the connection. Default 30 seconds. Minimum 15 seconds.
     * WinHTTP & libcurl support this option.
     * No-op for WinINet and IXMLHTTPRequest2 client.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    int64 tcpKeepAliveIntervalMs = 0;

    /**
     * Average transfer speed in bytes per second that the transfer should be below during the request timeout interval for it to be considered too slow and abort.
     * Default 1 byte/second. Only for CURL client currently.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    int64 lowSpeedLimit = 0;

    /**
     * Override the http endpoint used to talk to a service.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString endpointOverride;

    /**
     * If you have users going through a proxy, set the proxy scheme here. Default HTTP
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString proxyScheme;

    /**
     * If you have users going through a proxy, set the host here.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString proxyHost;

    /**
     * If you have users going through a proxy, set the port here.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    int32 proxyPort;

    /**
     * If you have users going through a proxy, set the username here.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString proxyUserName;

    /**
    * If you have users going through a proxy, set the password here.
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString proxyPassword;

    /**
    * SSL Certificate file to use for connecting to an HTTPS proxy.
    * Used to set CURLOPT_PROXY_SSLCERT in libcurl. Example: client.pem
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString proxySSLCertPath;

    /**
    * Type of proxy client SSL certificate.
    * Used to set CURLOPT_PROXY_SSLCERTTYPE in libcurl. Example: PEM
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString proxySSLCertType;

    /**
    * Private key file to use for connecting to an HTTPS proxy.
    * Used to set CURLOPT_PROXY_SSLKEY in libcurl. Example: key.pem
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString proxySSLKeyPath;

    /**
    * Type of private key file used to connect to an HTTPS proxy.
    * Used to set CURLOPT_PROXY_SSLKEYTYPE in libcurl. Example: PEM
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString proxySSLKeyType;

    /**
    * Passphrase to the private key file used to connect to an HTTPS proxy.
    * Used to set CURLOPT_PROXY_KEYPASSWD in libcurl. Example: password1
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString proxySSLKeyPassword;

    /**
    * Calls to hosts in this vector will not use proxy configuration
    */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    TArray<FString> nonProxyHosts;

    /**
     * If you need to test and want to get around TLS validation errors, do that here.
     * you probably shouldn't use this flag in a production scenario.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    bool verifySSL = false;

    /**
     * If you need to test and want to get around TLS validation errors, do that here.
     * you probably shouldn't use this flag in a production scenario.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString caPath;

    /**
     * If you need to test and want to get around TLS validation errors, do that here.
     * you probably shouldn't use this flag in a production scenario.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString caFile;

    /**
     * Override the http implementation the default factory returns.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    ETransferLibType httpLibOverride;

    /**
     * Sets the behavior how http stack handles 30x redirect codes.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    EFollowRedirectsPolicy followRedirects;

    /**
     * Only works for Curl http client.
     * Curl will by default add "Expect: 100-Continue" header in a Http request so as to avoid sending http
     * payload to wire if server respond error immediately after receiving the header.
     * Set this option to true will tell Curl to send http request header and body together.
     * This can save one round-trip time and especially useful when the payload is small and network latency is more important.
     * But be careful when Http request has large payload such S3 PutObject. You don't want to spend long time sending a large payload just getting a error response for server.
     * The default value will be false.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    bool disableExpectHeader = false;

    /**
     * If set to true clock skew will be adjusted after each http attempt, default to true.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    bool enableClockSkewAdjustment = false;

    /**
     * Enable host prefix injection.
     * For services whose endpoint is injectable. e.g. servicediscovery, you can modify the http host's prefix so as to add "data-" prefix for DiscoverInstances request.
     * Default to true, enabled. You can disable it for testing purpose.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    bool enableHostPrefixInjection = false;

    /**
     * Enable endpoint discovery
     * For some services to dynamically set up their endpoints for different requests.
     * Defaults to false, it's an opt-in feature.
     * If disabled, regional or overriden endpoint will be used instead.
     * If a request requires endpoint discovery but you disabled it. The request will never succeed.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    bool enableEndpointDiscovery = false;

    /**
     * profileName in config file that will be used by this object to reslove more configurations.
     */
    UPROPERTY(EditAnywhere, BlueprintReadWrite, Category="AWS Core")
    FString profileName;

#if WITH_CORE
public:
    Aws::Client::ClientConfiguration toAWS() const {
        Aws::Client::ClientConfiguration awsClientConfiguration;
        if (!(this->userAgent.IsEmpty())) {
            awsClientConfiguration.userAgent = TCHAR_TO_UTF8(*this->userAgent);
        }
        awsClientConfiguration.scheme = Aws::Http::SchemeMapper::FromString(TCHAR_TO_UTF8(*this->scheme));
        awsClientConfiguration.region = TCHAR_TO_UTF8(*this->region);
        awsClientConfiguration.useDualStack = this->useDualStack;
        awsClientConfiguration.maxConnections = static_cast<unsigned int>(this->maxConnections);
        awsClientConfiguration.httpRequestTimeoutMs = static_cast<unsigned int>(this->httpRequestTimeoutMs);
        awsClientConfiguration.requestTimeoutMs = this->requestTimeoutMs;
        awsClientConfiguration.connectTimeoutMs = this->connectTimeoutMs;
        awsClientConfiguration.enableTcpKeepAlive = this->enableTcpKeepAlive;
        awsClientConfiguration.tcpKeepAliveIntervalMs = static_cast<unsigned long>(this->tcpKeepAliveIntervalMs);
        awsClientConfiguration.lowSpeedLimit = static_cast<unsigned long>(this->lowSpeedLimit);
        awsClientConfiguration.endpointOverride = TCHAR_TO_UTF8(*this->endpointOverride);
        awsClientConfiguration.proxyScheme = Aws::Http::SchemeMapper::FromString(
                TCHAR_TO_UTF8(*this->proxyScheme));
        awsClientConfiguration.proxyHost = TCHAR_TO_UTF8(*this->proxyHost);
        awsClientConfiguration.proxyPort = this->proxyPort;
        awsClientConfiguration.proxyUserName = TCHAR_TO_UTF8(*this->proxyUserName);
        awsClientConfiguration.proxyPassword = TCHAR_TO_UTF8(*this->proxyPassword);
        awsClientConfiguration.proxySSLCertPath = TCHAR_TO_UTF8(*this->proxySSLCertPath);
        awsClientConfiguration.proxySSLCertType = TCHAR_TO_UTF8(*this->proxySSLCertType);
        awsClientConfiguration.proxySSLKeyPath = TCHAR_TO_UTF8(*this->proxySSLKeyPath);
        awsClientConfiguration.proxySSLKeyType = TCHAR_TO_UTF8(*this->proxySSLKeyType);
        awsClientConfiguration.proxySSLKeyPassword = TCHAR_TO_UTF8(*this->proxySSLKeyPassword);
        awsClientConfiguration.nonProxyHosts = Aws::Utils::Array<Aws::String>(this->nonProxyHosts.Num());
        for (int i = 0; i < this->nonProxyHosts.Num(); i++) {
            awsClientConfiguration.nonProxyHosts[i] = Aws::String(TCHAR_TO_UTF8(*this->nonProxyHosts[i]));
        }
        awsClientConfiguration.verifySSL = this->verifySSL;
        awsClientConfiguration.caPath = TCHAR_TO_UTF8(*this->caPath);
        awsClientConfiguration.caFile = TCHAR_TO_UTF8(*this->caFile);
        switch (this->httpLibOverride) {
            case ETransferLibType::CURL_CLIENT:
                awsClientConfiguration.httpLibOverride = Aws::Http::TransferLibType::CURL_CLIENT;
                break;
            case ETransferLibType::WIN_INET_CLIENT:
                awsClientConfiguration.httpLibOverride = Aws::Http::TransferLibType::WIN_INET_CLIENT;
                break;
            case ETransferLibType::WIN_HTTP_CLIENT:
                awsClientConfiguration.httpLibOverride = Aws::Http::TransferLibType::WIN_HTTP_CLIENT;
                break;
        }
        switch (this->followRedirects) {
            case EFollowRedirectsPolicy::DEFAULT:
                awsClientConfiguration.followRedirects = Aws::Client::FollowRedirectsPolicy::DEFAULT;
                break;
            case EFollowRedirectsPolicy::ALWAYS:
                awsClientConfiguration.followRedirects = Aws::Client::FollowRedirectsPolicy::ALWAYS;
                break;
            case EFollowRedirectsPolicy::NEVER:
                awsClientConfiguration.followRedirects = Aws::Client::FollowRedirectsPolicy::NEVER;
                break;
        }
        awsClientConfiguration.disableExpectHeader = this->disableExpectHeader;
        awsClientConfiguration.enableClockSkewAdjustment = this->enableClockSkewAdjustment;
        awsClientConfiguration.enableHostPrefixInjection = this->enableHostPrefixInjection;
        awsClientConfiguration.enableEndpointDiscovery = this->enableEndpointDiscovery;
        if (!(this->profileName.IsEmpty())) {
            awsClientConfiguration.profileName = TCHAR_TO_UTF8(*this->profileName);
        }
        return awsClientConfiguration;
    };
#endif
};
