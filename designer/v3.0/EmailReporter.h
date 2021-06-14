#ifndef __EMAIL_REPORTER_H__
#define __EMAIL_REPORTER_H__

#include <string>

class StatViewer;
class Aggregator;
class MetricsStorage;
class EmailReporter
{
public:
    EmailReporter(MetricsStorage *metricsStorage, Aggregator *aggregator, StatViewer *viewer);
    ~EmailReporter();

    void addToAddress(std::string address);

    void startDailyReport();

private:
    MetricsStorage*    _metricsStorage;
    Aggregator*        _aggregator;
    StatViewer*        _viewer;

    std::string        _emailAddress;
};

#endif