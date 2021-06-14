//#include "CommonDef.h"

#include "EmailReporter.h"
#include "StatViewer.h"
#include "MetricsStorage.h"
#include "Aggregator.h"

EmailReporter::EmailReporter(MetricsStorage *metricsStorage, Aggregator *aggregator, StatViewer *viewer)
{
    _metricsStorage = metricsStorage;
    _aggregator = aggregator;
    _viewer = viewer;
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
    RequestStat requestStat = _aggregator->aggregate(requestInfos);
    _viewer->output(requestStat, 20);

#if 0
    printf("\n");
    LOG("Email max:%d, min:%d, avg:%d", requestStat.maxResponseTime, requestStat.minResponseTime, requestStat.avgResponseTime);
#endif
}
