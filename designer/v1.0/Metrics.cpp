#include <string>
#include <map>
#include <iostream>
#include <vector>
#include <time.h>
#include <stdio.h>
#include <stddef.h>
#include <unistd.h>

using namespace std;

char* getNowTime()
{
    time_t timer, timer2;
    struct tm *tblock;
    timer = time(NULL);    
    tblock = localtime(&timer);

    return asctime(tblock);
}

class Metrics 
{
public:
    Metrics()
    {

    }

    ~Metrics()
    {

    }

    void recordResponseTime(std::string apiName, std::string responseTime)
    {        
        _responseTimeMap.insert(make_pair(apiName, responseTime));
    }

    void recordTimestamp(std::string apiName, std::string timestamp)
    {
        _timeMap.insert(make_pair(apiName, timestamp));
    }

    void startRepeateReport(int period)
    {
        for (auto& it : _timeMap)
        {
            cout << "func:" << __FUNCTION__ << " line:" << __LINE__ << " timestamp: apiName:" << it.first << " time:" << it.second << endl;
        }

        for (auto& it : _responseTimeMap)
        {
            cout << "func:" << __FUNCTION__ << " line:" << __LINE__ << " resp: apiName:" << it.first << " time:" << it.second << endl;
        }
    }

private:
    std::map<std::string, std::string> _responseTimeMap;
    std::map<std::string, std::string> _timeMap;
};

class UserController
{
public:
    UserController(Metrics *metrics) : _metrics(metrics)
    {

    }

    ~UserController()
    {

    }

    void regist(std::string user)
    {
        _metrics->recordTimestamp(user, getNowTime());

        //...

        _metrics->recordResponseTime(user, "1");
    }

    void login(std::string telephone, std::string password)
    {
        _metrics->recordTimestamp(telephone, getNowTime());

        //...

        _metrics->recordResponseTime(telephone, "2");
    }

    void startReport(int period)
    {
        _metrics->startRepeateReport(60);
    }

private:
    Metrics*    _metrics;
    int         _currentTime;
};

int main(void)
{    
    UserController userController(new Metrics());
    userController.regist("regist");
    sleep(1);
    userController.login("login", "123");

    userController.startReport(60);

    return 0;
}