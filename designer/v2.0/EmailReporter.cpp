#include "CommonDef.h"
#include "Aggregator.h"
#include "EmailReporter.h"
#include "MetricsStorage.h"

EmailReporter::EmailReporter(MetricsStorage *metricsStorage)
{
    _metricsStorage = metricsStorage;
}
    
EmailReporter::~EmailReporter()
{

}

void EmailReporter::addToAddress(std::string address)
{
    _emailAddress = address;;
}

void EmailReporter::startDailyReport()
{
    std::vector<RequestInfo> requestInfos = _metricsStorage->getRequestInfos("regist", 1, 2);
    RequstStat requestStat = Aggregator::aggregate(requestInfos);

    printf("\n");
    LOG("Email max:%d, min:%d, avg:%d", requestStat.maxResponseTime, requestStat.minResponseTime, requestStat.avgResponseTime);
}
