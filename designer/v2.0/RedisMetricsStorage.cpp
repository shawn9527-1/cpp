#include "RedisMetricsStorage.h"

RedisMetricsStorage::RedisMetricsStorage()
{

}

RedisMetricsStorage::~RedisMetricsStorage()
{
    
}

void RedisMetricsStorage::saveRequestInfo(RequestInfo requestInfo)
{    
    _timeMap.insert(make_pair(requestInfo._apiName, requestInfo._timestamp));
    _responseTimeMap.insert(make_pair(requestInfo._apiName, requestInfo._responseTime));
}

std::vector<RequestInfo> RedisMetricsStorage::getRequestInfos(std::string apiName, int startTime, int endTime)
{
    std::vector<RequestInfo> requestInfoVec;
    RequestInfo requestInfo;
    requestInfo._apiName = apiName;
    auto it = _timeMap.find(apiName);
    if (it != _timeMap.end())
    {        
        requestInfo._timestamp = it->second;
    }

    auto it1 = _responseTimeMap.find(apiName);
    if (it1 != _responseTimeMap.end())
    {
        requestInfo._responseTime = it1->second;
    }

    requestInfoVec.push_back(requestInfo);
    return requestInfoVec;
}

