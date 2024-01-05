#include <iostream>
#include "loadBalancer.h"
using namespace std;





// add random requests -> if requests in queue is greater or equal to max requests -> +1 server(maxreq=servers*20) 
// vector.resize(numservers + 1)
// max req += 20
// else if num servers*15 > num of requests -> decrease by 1
// while rand# %5 == 0 or another -> chat? randomly add requests
// request = q.pop() -> adding queue element to web servers
