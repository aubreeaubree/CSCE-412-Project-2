#pragma once
#include <string>
#include "webserver.h"
#include "requestqueue.h"
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