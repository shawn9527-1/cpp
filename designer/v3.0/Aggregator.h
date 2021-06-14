#ifndef __AGGREGATOR_H__
#define __AGGREGATOR_H__

#include <vector>
#include "CommonDef.h"

class Aggregator
{
public:
    Aggregator();
    ~Aggregator();

    RequestStat aggregate(std::vector<RequestInfo> requestInfos);

    RequestStat doAggregate(std::vector<RequestInfo> requestInfos, int duration);
};

#endif