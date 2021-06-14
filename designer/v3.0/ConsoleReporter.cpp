#include "MetricsStorage.h"
#include "ConsoleReporter.h"
#include "Aggregator.h"
#include "StatViewer.h"

ConsoleReporter::ConsoleReporter(MetricsStorage* metricsStorage,  Aggregator* aggregator, StatViewer* viewer)
{
    _metricsStorage = metricsStorage;
    _aggregater = aggregator;
    _viewer = viewer;
}

ConsoleReporter::~ConsoleReporter()
{

}

void ConsoleReporter::startRepeatedReport(int period, int duration)
{
    std::vector<RequestInfo> requestInfos = _metricsStorage->getRequestInfos("regist", 11, 22);    
    RequestStat requestStat = _aggregater->aggregate(requestInfos);    
    _viewer->output(requestStat, 10);

#if 0
    LOG("max:%d, min:%d, avg:%d", requestStat.maxResponseTime, requestStat.minResponseTime, requestStat.avgResponseTime);

    printf("\n");

    std::vector<RequestInfo> requestInfosLoggin = _metricsStorage->getRequestInfos("login", 11, 22);
    RequestStat requestStatLogin = Aggregator::aggregate(requestInfosLoggin);    
    LOG("max:%d, min:%d, avg:%d", requestStatLogin.maxResponseTime, requestStatLogin.minResponseTime, requestStatLogin.avgResponseTime);    
#endif    
}