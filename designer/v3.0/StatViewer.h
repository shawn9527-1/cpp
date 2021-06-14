#ifndef __STAT_VIEWER_H__
#define __STAT_VIEWER_H__

#include "CommonDef.h"

class StatViewer
{
public:    
    virtual void output(RequestStat stat, int period) = 0;
};

#endif