#include "dataPulling.h"
#include "mergeSort.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

MergeSort::MergeSort() {

};

// Was told could use one algorithm/data structure that is not from scratch due to one team member leaving
// Reference: Used Slide 52 of the Sorting lecture slides for merge sort
// Currently have vector<int> &vec but might have to change to vector<string> b/c line read in as string
// Definitely revisit the dataPulling class/functions to see if extract certain columns instead
// Just a placeholder merge sort implementation right now; need to adjust to fit what is needed for this project
void MergeSort::helperMerge(vector<int> &vec, int left, int mid, int right) {
    // Split into two arrays
    int nSmaller = mid - left + 1;
    int nGreater = right - mid;
    int X[nSmaller];
    int Y[nGreater];

    for (int i = 0; i < nSmaller; i++) { // Fill in X vector (left side)
        X[i] = vec[left + i];
    }
    for (int j = 0; j < nGreater; j++) { // Fill in Y vector (right side)
        Y[j] = vec[mid + 1 + j];
    }

    // Merge vectors X and Y into one vector
    int i = 0;
    int j = 0;
    int k = left;
    while (i < nSmaller && j < nGreater) {
        // Go through, compare to sort the two vectors, merge together
        if (X[i] <= Y[j]) {
            vec[k] = X[i];
            i++;
        }
        else {
            vec[k] = Y[j];
            j++;
        }
        k++;
    }

    // Append any remaining elements in individual vectors X and Y to the new combined vector
    while (i < nSmaller) {
        vec[k] = X[i];
        i++;
        k++;
    }

    while (j < nGreater) {
        vec[k] = Y[j];
        j++;
        k++;
    }
}

void MergeSort::mergeSort(vector<int> &vec, int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(vec, left, mid); // Sorts the side that is less than the middle
        mergeSort(vec, mid + 1, right); // Sorts the side that is greater than the middle
        helperMerge(vec, left, mid, right); // Merges the two vectors now that they are sorted
        // Vector should now be fully sorted
    }
}






