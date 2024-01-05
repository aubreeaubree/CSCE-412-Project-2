#include <iostream>
#include "request.h"
#include "loadBalancer.h"
using namespace std;

//populate request queue 
int main(){
    int maxClock = 200; //user input later
    int numServers = 10; // user input later
    loadBalancer load;
    // generate full queue
    for (long unsigned int i = 0; i < numServers * 20; i++){
        request reqMade;
        load.addReq(reqMade);
    }

    for (size_t i = 0; i < maxClock; i++){
        if (rand() % 3 == 0){
            request reqMade;
            load.addReq(reqMade);
        }
        load.runWorkload();
        
    }
    
    // add random requests -> if requests in queue is greater or equal to max requests -> +1 server(maxreq=servers*20)
    // vector.resize(numservers + 1)
    // max req += 20
    // else if num servers*15 > num of requests -> decrease by 1
    // while rand# %5 == 0 or another -> chat? randomly add requests
    // request = q.pop() -> adding queue element to web servers

}