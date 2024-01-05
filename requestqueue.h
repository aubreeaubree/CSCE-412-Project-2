#pragma once
#include <queue>
#include "request.h"

class requestqueue{
public:
    void popReq();
    void pushReq(const request& newRequest);
    bool isEmpty();
    const request& front();
    size_t sizeQ();
private:
    queue<request> q;
};