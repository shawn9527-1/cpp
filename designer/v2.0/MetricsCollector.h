#ifndef __METRICS_COLLECTOR_H__
#define __METRICS_COLLECTOR_H__

#include "CommonDef.h"

class MetricsStorage;
class MetricsCollector
{
public:
    MetricsCollector(MetricsStorage *metricsStorage);
    ~MetricsCollector();

    void recordRequest(RequestInfo requestInfo);

private:
    MetricsStorage*    _metricsStorage;    
};

#endif