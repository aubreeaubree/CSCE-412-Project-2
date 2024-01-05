#pragma once
#include <string>
#include "webserver.cpp"
#include "requestqueue.cpp"
using namespace std;

class loadBalancer{
public:
    void runWorkload();
    void addReq(request reqAdded);

private:
    vector<webserver> workload;
    requestqueue q;
    int userTime;
};