#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class MergeSort {
private:

public:
    MergeSort();
    void helperMerge(vector<int> &vec, int left, int mid, int right);
    void mergeSort(vector<int> &vec, int left, int right);
};