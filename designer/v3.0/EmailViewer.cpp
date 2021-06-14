#include <iostream>

#include "EmailViewer.h"

using namespace std;

EmailViewer::EmailViewer()
{

}

EmailViewer::~EmailViewer()
{

}

void EmailViewer::output(RequestStat stat, int period)
{
    cout << "***********Email*********" << endl;
    cout << "maxResponseTime:" << stat.maxResponseTime << endl;
    cout << "minResponseTime:" << stat.minResponseTime << endl;
    cout << "avgResponseTime:" << stat.avgResponseTime << endl;
}