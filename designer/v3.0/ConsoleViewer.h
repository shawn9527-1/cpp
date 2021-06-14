#ifndef __CONSOLE_VIEWER_H__
#define __CONSOLE_VIEWER_H__

#include "StatViewer.h"

class ConsoleViewer : public StatViewer
{
public:
    ConsoleViewer();
    ~ConsoleViewer();

    virtual void output(RequestStat stat, int period) override;
};

#endif