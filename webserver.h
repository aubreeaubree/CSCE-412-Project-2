#pragma once
#include <string>
#include <vector>
#include "request.h"
using namespace std;

class webserver{
public:
    // Function to set a new request for the web server
    void setRequest(request req);
    // Function to update the time left for the current request
    int newTimeLeft();
    // Function to check if the current request is complete
    bool reqComplete();
    // Function to check if the web server has an assigned request
    bool hasRequest();
    // Function to print the time left for the current request
    int printTime();
private:
    // Variable to store the time left for the current request
    int timeLeftInReq = 0;
    request currReq;
    // Flag indicating whether the web server has an assigned request
    bool boxIsFull = false;
};