#include "MetricsCollector.h"
#include "RedisMetricsStorage.h"
#include "ConsoleReporter.h"
#include "EmailReporter.h"

int main(void)
{
    MetricsStorage *storage = new RedisMetricsStorage();

    //依赖注入方式，不修改代码情况下，更换存储方式
    ConsoleReporter *consoleReporter = new ConsoleReporter(storage);    

    //log to console
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

    consoleReporter->startRepeatedReport(1, 2);

    //log to email
    EmailReporter *emailReporter = new EmailReporter(storage);
    emailReporter->addToAddress("xz@qq.com");
    emailReporter->startDailyReport();

    return 0;
}