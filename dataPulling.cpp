#include "dataPulling.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

dataPulling::dataPulling() {}

void dataPulling::readFile() {
    ifstream musicData("dataset.csv");
    vector<string> dataset;
    if (!musicData.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }
    
    string datapoints;
}