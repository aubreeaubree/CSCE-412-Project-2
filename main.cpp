#include <iostream>
#include "request.h"
#include "loadBalancer.h"
using namespace std;

//populate request queue 
int main(){
    int maxClock = 10000;
    cout << "How many clock ticks do you want to wait for: " << maxClock;
    //cin >> maxClock;
    int numServers = 10; 
    cout << "How many servers to start: " << numServers;
    //cin >> numServers;

    // Create an instance of loadBalancer
    loadBalancer load;
    // Generate a full request queue
    for (long unsigned int i = 0; i < numServers * 20; i++){
        request reqMade;
        load.addReq(reqMade);
    }

    for (size_t i = 0; i < maxClock; i++){
        // Generate random requests periodically
        if (rand() % 3 == 0){
            request reqMade;
            load.addReq(reqMade);
        }
        load.runWorkload();
        if ((i % 100) == 0){
            load.printStatus();
        }
    }

}