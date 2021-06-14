#ifndef __METRICS_STORAGE_H__
#define __METRICS_STORAGE_H__

#include <vector>
#include "CommonDef.h"

class MetricsStorage
{
public:
    virtual void saveRequestInfo(RequestInfo requestInfo) = 0;
    virtual std::vector<RequestInfo> getRequestInfos(std::string apiName, int startTime, int endTime) = 0;

};

#endif