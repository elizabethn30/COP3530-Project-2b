#include "dataPulling.h"
#include "mergeSort.h"
#include "song.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

MergeSort::MergeSort() {

};

// Does vec need to be passed by reference?
vector<Song> MergeSort::genreSort(vector<Song> vec, string genre) {
    vector<Song> genreSorted;
    for (int i = 0; i < vec.size(); i++) {
        if (vec[i].genre == genre) {
            genreSorted.push_back(vec[i]);
        }
    }
    return genreSorted;
}

// Reference: Used Slide 52 of the Sorting lecture slides as guide for merge sort
// Redo of Merge Sort
void MergeSort::helperMerge(vector<Song> &vec, int left, int mid, int right) {
    vector<Song> leftVec;
    vector<Song> rightVec;
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
        if (leftVec[sortingLeftIndex].popularityScore <= rightVec[sortingRightIndex].popularityScore) {
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
void MergeSort::mergeSort(vector<Song> &vec, int left, int right) {
    int mid;

    if (left < right) {
        mid = left + (right - left) / 2;
        mergeSort(vec, left, mid); // Sort the left side
        mergeSort(vec, mid + 1, right); // Sort the right side
        helperMerge(vec, left, mid, right); // Combine the two vectors
        // left++;
    }
}

// Input the merge sorted vector and get back only the top 5 for the ranking
vector<Song> MergeSort::getTopMergeSort(vector<Song> &vec, int count) {
    vector<Song> topMergeSort;
    int end = count + 1;
    for (int i = 1; i < end; i++) {
        topMergeSort.push_back(vec[vec.size()-i]);
    }
    return topMergeSort;
}