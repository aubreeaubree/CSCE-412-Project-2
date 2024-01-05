#include <iostream>
#include "webserver.h"
using namespace std;

void webserver::setRequest(request req){
    currReq = req;
    timeLeftInReq = req.timeForTask;
    boxIsFull = true;
}

int webserver::newTimeLeft(){
    return timeLeftInReq--;
}

bool webserver::reqComplete(){
    if (timeLeftInReq == 0){
        boxIsFull = false;
        return true;
    }
    return false;
}
bool webserver::hasRequest(){
    if (boxIsFull){
        return true;        
    }
    return false;
}
