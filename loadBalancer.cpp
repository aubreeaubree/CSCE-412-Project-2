/** @file loadBalancer.cpp
 *  @brief Implements loadBalancer class.
*/

#include <iostream>
#include "loadBalancer.h"

using namespace std;

loadBalancer::loadBalancer(){
    userTime = 0;
    for (size_t i = 0; i < 10; i++){
        webserver server;
        workload.push_back(server);
    }
    
}

loadBalancer::loadBalancer(size_t serverCount){
    userTime = 0;
    for (size_t i = 0; i < serverCount; i++){
        webserver server;
        workload.push_back(server);
    }
}

void loadBalancer::runWorkload(){
    // Check for workload adjustments every 100 seconds
    if (userTime % 100 == 0){
        // Add a new web server if the queue size is large
        if (q.sizeQ() > 25 * workload.size()){
            webserver wsNew;
            workload.push_back(wsNew);
            cout << "\nServer has been added" << endl;
        }
        // Remove a web server if the queue size is small
        else if (q.sizeQ() < 15 * workload.size()){
            workload.pop_back();
            cout << "\nServer has been removed" << endl;
        }
    }
    // Iterate through each web server in the workload
    for (size_t w = 0; w < workload.size(); w++){
        // Assign a request to an idle web server if available in the queue
        if (!workload.at(w).hasRequest() && !q.isEmpty()){
            workload.at(w).setRequest(q.front());
            q.popReq();
        }
        // Update the remaining time for a request if a web server has an assigned request
        else if (workload.at(w).hasRequest()){
            workload.at(w).newTimeLeft();
            // Assign a new request if the current request is complete and the queue is not empty
            if (workload.at(w).reqComplete() && !q.isEmpty()){
                workload.at(w).setRequest(q.front());
                q.popReq();
            }
        }   
    }
    userTime++;
}

void loadBalancer::addReq(request reqAdded){
    // Add a request to the request queue accounts for random activity
    q.pushReq(reqAdded);
}

void loadBalancer::printStatus() {
    cout << "\n======================================" << endl;
    cout << "======== Load Balancer Status ========" << endl;
    cout << "======================================" << endl;
    cout << "Current queue size: " << q.sizeQ() << endl;
    cout << "Number of servers: " << workload.size() << endl << endl;
        // Iterate through each web server in the workload
        for (size_t w = 0; w < workload.size(); w++){
        // Check if the web server has an assigned request
        cout << "Server #" << w + 1 << " Status" << endl;
        if (workload.at(w).hasRequest()) {
            // Print details of the web server's status when a request is assigned
            cout << "Time left in request: " << workload.at(w).printTime() << " seconds\n";
            cout << "Source IP: " << workload.at(w).getRequest().sourceIP << endl;
            cout << "Destination IP: " << workload.at(w).getRequest().destinationIP << endl;
        } 
        else {
            // Print status when no request is assigned to the web server
            cout << "  No request assigned.\n";
        }
        cout << "---------------------------------\n";
    }
}

