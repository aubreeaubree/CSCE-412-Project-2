/** @file requestqueue.cpp
 *  @brief Implements requestqueue class.
 */
#include <iostream>
#include "requestqueue.h"
#include "request.h"
using namespace std;

// Function to remove the front request from the queue
void requestqueue::popReq(){
    if (q.empty() == false){
        q.pop();
    }
}
// Function to add a new request to the back of the queue
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