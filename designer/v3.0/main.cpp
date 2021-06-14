#include "MetricsCollector.h"
#include "RedisMetricsStorage.h"
#include "ConsoleReporter.h"
#include "EmailReporter.h"
#include "EmailViewer.h"
#include "ConsoleViewer.h"
#include "Aggregator.h"

int main(void)
{
    //log to console
    MetricsStorage *storage = new RedisMetricsStorage();

    MetricsCollector *metricsCollerotr = new MetricsCollector(storage);
    RequestInfo requst1;
    requst1._apiName = "regist";
    requst1._responseTime = 12;
    requst1._timestamp = "111";
    metricsCollerotr->recordRequest(requst1);

    RequestInfo requst2;
    requst2._apiName = "login";
    requst2._responseTime = 123;
    requst2._timestamp = "1113";
    metricsCollerotr->recordRequest(requst2);

    Aggregator *aggregator = new Aggregator();    
    StatViewer *statViewer = new ConsoleViewer();

    //依赖注入方式，不修改代码情况下，更换存储方式
    ConsoleReporter *consoleReporter = new ConsoleReporter(storage, aggregator, statViewer);
    consoleReporter->startRepeatedReport(1, 2);

    //log to email
    StatViewer *statViewer1 = new EmailViewer();    
    EmailReporter *emailReporter = new EmailReporter(storage, aggregator, statViewer1);
    emailReporter->addToAddress("xz@qq.com");
    emailReporter->startDailyReport();

    return 0;
}