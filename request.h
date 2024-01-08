/** @file reuest.h
 *  @brief Defines reuest class.
 */
#pragma once
#include <string>
using namespace std;

struct request {
    /// Default constructor initializes source IP, destination IP, and time for task
    string sourceIP = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
    string destinationIP = to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256) + "." + to_string(rand() % 256);
    int timeForTask = 4 + (rand() % 97);
};
