#include "Aggregator.h"

Aggregator::Aggregator()
{

}

Aggregator::~Aggregator()
{

}

RequestStat Aggregator::aggregate(std::vector<RequestInfo> requestInfos)
{
    RequestStat requestStat = doAggregate(requestInfos, 10);
}

RequestStat Aggregator::doAggregate(std::vector<RequestInfo> requestInfos, int duration)
{
    for (auto& it : requestInfos)
    {
        LOG("apiname:%s, respTime:%d, timestamp:%s", it._apiName.c_str(), it._responseTime, it._timestamp.c_str());
    }

    RequestStat requestStat;
    requestStat.maxResponseTime = 999;
    requestStat.minResponseTime = 1;
    requestStat.count = 100;
    requestStat.avgResponseTime = 500;
    requestStat.tps = 2;
    return requestStat;
}
