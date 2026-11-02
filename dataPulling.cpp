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

    // musicData.open("dataset.csv");
    if (!musicData.is_open()) {
        cout << "Error opening file" << endl;
        return;
    }

    string datapoints;
    while (getline(musicData, datapoints)) {
        dataset.push_back(datapoints);
    }
    // cout << "hello world" << endl;
    // cout << dataset.size() << endl;
    cout << dataset[0] << endl;
    cout << dataset[1] << endl;

    // Get the datapoints for each column
    // for (int j = 1; j < dataset.size(); j++) {
    //     for (int i = 0; i < dataset.size(); i++) {
    //
    //     }
    // }

    // Get the datapoints for each column
    // Artists column
    // for (int i = 1; i < dataset.size(); i++) {
    //
    // }
}