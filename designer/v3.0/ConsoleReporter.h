#ifndef __CONSOLE_REPORTER_H__
#define __CONSOLE_REPORTER_H__

class StatViewer;
class Aggregator;
class MetricsStorage;
class ConsoleReporter
{
public:
    ConsoleReporter(MetricsStorage* metricsStorage,  Aggregator* aggregator, StatViewer* viewer);
    ~ConsoleReporter();

    void startRepeatedReport(int period, int duration);

private:
    MetricsStorage* _metricsStorage;
    Aggregator*     _aggregater;
    StatViewer*     _viewer;
};

#endif