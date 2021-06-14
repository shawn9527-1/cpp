#ifndef __EMAIL_REPORTER_H__
#define __EMAIL_REPORTER_H__

#include <string>

class MetricsStorage;
class EmailReporter
{
public:
    EmailReporter(MetricsStorage *metricsStorage);
    ~EmailReporter();

    void addToAddress(std::string address);

    void startDailyReport();

private:
    MetricsStorage*    _metricsStorage;
    std::string        _emailAddress;
};

#endif