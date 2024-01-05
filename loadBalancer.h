#pragma once
#include <string>
#include "webserver.h"
#include "requestqueue.h"
using namespace std;

class loadBalancer{
public:
    //Funtion to perform the load balancing
    void runWorkload();
    // Function to add a request to the load balancer's queue
    void addReq(request reqAdded);
    // Function to print the status of the load balancer
    void printStatus();

private:
    vector<webserver> workload;
    requestqueue q;
    int userTime;
};