#ifndef __REDIS_METRICS_STORAGE_H__
#define __REDIS_METRICS_STORAGE_H__

#include <string>
#include <map>
#include "MetricsStorage.h"

class RedisMetricsStorage : public MetricsStorage
{
public:
    RedisMetricsStorage();
    ~RedisMetricsStorage();

    virtual void saveRequestInfo(RequestInfo requestInfo) override;
    virtual std::vector<RequestInfo> getRequestInfos(std::string apiName, int startTime, int endTime) override;

private:
    std::map<std::string, int> _responseTimeMap;
    std::map<std::string, std::string> _timeMap;
};

#endif