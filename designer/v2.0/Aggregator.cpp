#include "Aggregator.h"

Aggregator::Aggregator()
{

}

Aggregator::~Aggregator()
{

}

RequstStat Aggregator::aggregate(std::vector<RequestInfo> requestInfos)
{
    for (auto& it : requestInfos)
    {
        LOG("apiname:%s, respTime:%d, timestamp:%s", it._apiName.c_str(), it._responseTime, it._timestamp.c_str());
    }

    RequstStat requestStat;
    requestStat.maxResponseTime = 999;
    requestStat.minResponseTime = 1;
    requestStat.count = 100;
    requestStat.avgResponseTime = 500;
    requestStat.tps = 2;
    return requestStat;
}
