#pragma once
#include <string>
using namespace std;

struct request {
    string sourceIP = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
    string destinationIP = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
    int timeForTask = 4 + (rand() % 97);
};
