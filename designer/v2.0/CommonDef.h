#ifndef __COMMON_DEF_H__
#define __COMMON_DEF_H__

#include <string>
#include <stdio.h>

#define LOG(fmt, args...) printf("[%s:%d]" fmt "\n", __func__, __LINE__, ##args)

struct RequestInfo
{
    std::string _apiName;
    int         _responseTime;
    std::string _timestamp;
};

struct RequstStat
{
    int maxResponseTime;
    int minResponseTime;
    int avgResponseTime;
    int count;
    int tps;
};

#endif