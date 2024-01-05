#include <iostream>
#include "loadBalancer.h"

using namespace std;

void loadBalancer::runWorkload(){
    // Check for workload adjustments every 100 seconds
    if (userTime % 100 == 0){
        // Add a new web server if the queue size is large
        if (q.sizeQ() > 25 * workload.size()){
            webserver wsNew;
            workload.push_back(wsNew);
        }
        // Remove a web server if the queue size is small
        else if (q.sizeQ() < 15 * workload.size()){
            workload.pop_back();
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
    cout << "======================================" << endl;
    cout << "======== Load Balancer Status ========" << endl;
    cout << "======================================" << endl;
    // Iterate through each web server in the workload
    for (size_t w = 0; w < workload.size(); w++) {
        // Check if the web server has an assigned request
        if (workload.at(w).hasRequest()) {
            // Print details of the web server's status when a request is assigned
            cout << "Time left in request: " << workload.at(w).printTime() << " seconds\n";
            cout << "Source IP: " << q.front().sourceIP << endl;
            cout << "Destination IP: " << q.front().destinationIP << endl;
        } 
        else {
            // Print status when no request is assigned to the web server
            cout << "  No request assigned.\n";
        }
        cout << "-------------------------\n";
    }
}

