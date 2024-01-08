/** @file webserver.cpp
 *  @brief Implements webserver class.
 */

#include <iostream>
#include "webserver.h"
using namespace std;

void webserver::setRequest(request req){
    currReq = req;
    timeLeftInReq = req.timeForTask;
    boxIsFull = true;
}

request webserver::getRequest(){
    return currReq;
}

// Decrement the time left for the current request and return the updated value
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
int webserver::printTime(){
    return timeLeftInReq;
}
