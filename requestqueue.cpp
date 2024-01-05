#include <iostream>
#include "requestqueue.h"
#include "request.h"
using namespace std;

void requestqueue::popReq(){
    if (q.empty() == false){
        q.pop();
    }
}
void requestqueue::pushReq(const request &newRequest){
    q.push(newRequest);
}
bool requestqueue::isEmpty(){
    return q.empty();
}
const request& requestqueue::front(){
    return q.front();
}

size_t requestqueue::sizeQ(){
    return q.size();
}