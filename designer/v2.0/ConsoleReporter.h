#ifndef __CONSOLE_REPORTER_H__
#define __CONSOLE_REPORTER_H__

class MetricsStorage;
class ConsoleReporter
{
public:
    ConsoleReporter(MetricsStorage* metricsStorage);
    ~ConsoleReporter();

    void startRepeatedReport(int period, int duration);

private:
    MetricsStorage* _metricsStorage;    
};

#endif