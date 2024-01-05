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
    cout << "hi";

}