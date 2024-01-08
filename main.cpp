/** @file main.cpp
 *  @brief Runs loadBalancer.
 */

#include <iostream>
#include "request.h"
#include "loadBalancer.h"
using namespace std;

//populate request queue 
int main(){
    srand(time(0));
    int maxClock;
    cout << "How many clock ticks do you want to wait for: ";
    cin >> maxClock;
    int numServers; 
    cout << "How many servers to start: ";
    cin >> numServers;
    cout << "Starting simulation. Requests between 4-100 clock cycles." << endl;

    // Create an instance of loadBalancer
    loadBalancer load;
    // Generate a full request queue
    for (long unsigned int i = 0; i < numServers * 20; i++){
        request reqMade;
        reqMade.sourceIP = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
        reqMade.destinationIP = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
        reqMade.timeForTask = 4 + (rand() % 97);
        load.addReq(reqMade);
    }

    for (size_t i = 0; i < maxClock; i++){
        // Generate random requests periodically
        if (rand() % 3 == 0){
            request reqMade;
            reqMade.sourceIP = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
            reqMade.destinationIP = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
            reqMade.timeForTask = 4 + (rand() % 97);
            load.addReq(reqMade);
        }
        load.runWorkload();
        if ((i % 100) == 0){
            load.printStatus();
        }
    }

    cout << "Simulation completed. Final status:" << endl;
    load.printStatus();
}