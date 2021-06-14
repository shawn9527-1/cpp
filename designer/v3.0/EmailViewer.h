#ifndef __EMAIL_VIEWER_H__
#define __EMAIL_VIEWER_H__

#include "StatViewer.h"

class EmailViewer : public StatViewer
{
public:
    EmailViewer();
    ~EmailViewer();

    virtual void output(RequestStat stat, int period);            
};

#endif