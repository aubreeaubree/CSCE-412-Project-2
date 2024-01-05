#pragma once
#include <string>
#include <vector>
#include "request.h"
using namespace std;

class webserver{
public:
    void setRequest(request req);
    int newTimeLeft();
    bool reqComplete();
    bool hasRequest();
private:
    int timeLeftInReq = 0;
    request currReq;
    bool boxIsFull = false;
};