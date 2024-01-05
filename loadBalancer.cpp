#include <iostream>
#include "loadBalancer.h"

using namespace std;

void loadBalancer::runWorkload(){
    for (size_t w = 0; w < workload.size(); w++){
        if (!workload.at(w).hasRequest() && !q.isEmpty()){
            workload.at(w).setRequest(q.front());
            q.popReq();
        }
        else if (workload.at(w).hasRequest()){
            workload.at(w).newTimeLeft();
            if (workload.at(w).reqComplete() && !q.isEmpty()){
                workload.at(w).setRequest(q.front());
                q.popReq();
            }
        }   
    }
    userTime++;
}

void loadBalancer::addReq(request reqAdded){
    q.pushReq(reqAdded);
}
