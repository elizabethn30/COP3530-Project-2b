#include "dataPulling.h"
#include "mergeSort.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

MergeSort::MergeSort() {

};

// Reference: Used Slide 52 of the Sorting lecture slides for merge sort
// Redo of Merge Sort
void MergeSort::helperMerge(vector<int> &vec, int left, int mid, int right) {
    vector<int> leftVec;
    vector<int> rightVec;
    int leftVecSize;
    int rightVecSize;

    // Gets the sizes of two respective vectors when you split the original 'vec' vector in half
    if ((left + right) % 2 == 0) { // Means there's an odd number of elements in original 'vec' vector
        leftVecSize = mid - left + 1; // Makes left vector "heavier" than right vector
        rightVecSize = right - mid;
    }
    else {
        leftVecSize = mid - left + 1;
        rightVecSize = right - mid; // Gets right vector excluding middle element
    }

    // Split original vector into two vectors
    int leftIndex = left;
    int rightIndex = mid + 1;
    while (leftIndex <= mid) { // Fills in left vector
        leftVec.push_back(vec[leftIndex]);
        leftIndex++;
    }

    while (rightIndex <= right) { // Fills in right vector
        rightVec.push_back(vec[rightIndex]);
        rightIndex++;
    }

    // Sort the vectors
    int sortingLeftIndex = 0;
    int sortingRightIndex = 0;
    int vecIndex = left;
    // Keeps going until one vector has gone through all of its elements
    while (sortingLeftIndex < leftVecSize && sortingRightIndex < rightVecSize) {
        if (leftVec[sortingLeftIndex] <= rightVec[sortingRightIndex]) {
            vec[vecIndex] = leftVec[sortingLeftIndex];
            sortingLeftIndex++;
            vecIndex++;
        }
        else {
            vec[vecIndex] = rightVec[sortingRightIndex];
            sortingRightIndex++;
            vecIndex++;
        }
    }

    // Puts any leftover elements into original 'vec' vector
    // Left and right vectors should both be sorted, so all elements in left vector are LESS than all elements in right vector
    while (sortingLeftIndex < leftVecSize) { // Leftover elements from left vector
        vec[vecIndex] = leftVec[sortingLeftIndex];
        sortingLeftIndex++;
        vecIndex++;
    }

    while (sortingRightIndex < rightVecSize) { // Leftover elements from right vector
        vec[vecIndex] = rightVec[sortingRightIndex];
        sortingRightIndex++;
        vecIndex++;
    }
}

// Should split the original vector up until we are left with only individual elements
void MergeSort::mergeSort(vector<int> &vec, int left, int right) {
    int mid;

    while (left < right) {
        mid = left + (right - left) / 2;
        mergeSort(vec, left, mid); // Sort the left side
        mergeSort(vec, mid + 1, right); // Sort the right side
        helperMerge(vec, left, mid, right); // Combine the two vectors
        left++;
    }
}