/** @file requestqueue.h
 *  @brief Defines reuestqueue class.
 */
#pragma once
#include <queue>
#include "request.h"

class requestqueue{
public:
    /// Function to remove the front request from the queue
    void popReq();
    /// Function to add a new request to the back of the queue
    void pushReq(const request& newRequest);
    bool isEmpty();
    const request& front();
    size_t sizeQ();
private:
    queue<request> q;
};