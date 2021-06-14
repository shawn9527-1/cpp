#include "MetricsStorage.h"
#include "ConsoleReporter.h"
#include "Aggregator.h"

ConsoleReporter::ConsoleReporter(MetricsStorage* metricsStorage)
{
    _metricsStorage = metricsStorage;
}

ConsoleReporter::~ConsoleReporter()
{

}

void ConsoleReporter::startRepeatedReport(int period, int duration)
{
    std::vector<RequestInfo> requestInfos = _metricsStorage->getRequestInfos("regist", 11, 22);    
    RequstStat requestStat = Aggregator::aggregate(requestInfos);    
    LOG("max:%d, min:%d, avg:%d", requestStat.maxResponseTime, requestStat.minResponseTime, requestStat.avgResponseTime);

    printf("\n");

    std::vector<RequestInfo> requestInfosLoggin = _metricsStorage->getRequestInfos("login", 11, 22);
    RequstStat requestStatLogin = Aggregator::aggregate(requestInfosLoggin);    
    LOG("max:%d, min:%d, avg:%d", requestStatLogin.maxResponseTime, requestStatLogin.minResponseTime, requestStatLogin.avgResponseTime);    
}