#ifndef __AGGREGATOR_H__
#define __AGGREGATOR_H__

#include <vector>
#include "CommonDef.h"

class Aggregator
{
public:
    Aggregator();
    ~Aggregator();

    static RequstStat aggregate(std::vector<RequestInfo> requestInfos);
};

#endif