#include "ConsoleViewer.h"

ConsoleViewer::ConsoleViewer()
{

}

ConsoleViewer::~ConsoleViewer()
{

}

void ConsoleViewer::output(RequestStat stat, int period)
{
    LOG("*******console max:%d, min:%d, avg:%d", stat.maxResponseTime, stat.minResponseTime, stat.avgResponseTime);
}