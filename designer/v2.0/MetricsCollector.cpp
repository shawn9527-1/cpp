#include "MetricsStorage.h"
#include "MetricsCollector.h"

MetricsCollector::MetricsCollector(MetricsStorage *metricsStorage)
{
    _metricsStorage = metricsStorage;
}

MetricsCollector::~MetricsCollector()
{

}

void MetricsCollector::recordRequest(RequestInfo requestInfo)
{
    _metricsStorage->saveRequestInfo(requestInfo);
}