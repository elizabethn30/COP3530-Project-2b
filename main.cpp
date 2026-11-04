#include "dataPulling.h"
#include "minHeap.h"
#include <iostream>
#include <vector>
// #include <string>
// #include <fstream>
using namespace std;

int main() {
    // Just testing out the dataPulling class to make sure it works
    dataPulling example;
    example.readFile();
    // cout << "hello world" << endl;

    //sample scores just to test minHeap
    vector<int> scores = {46, 90, 73, 82, 99, 46};
    int k = 3;
    vector<int> rankedSongs = topKByPopularity(scores, k);
    cout<< "Top" << k << "songs:" << endl;
    for (int rank = 0; rank < static_cast<int>(rankedSongs.size()); rank++) {
        int index = rankedSongs[rank];
        cout << rank + 1 << "Song index: " << index << "\nPopularity: " << scores[index] << endl;
    }

    return 0;
}