#include "minHeap.h"
#include <vector>
#include <queue>
using namespace std;

struct HeapSong {
    int popularity;
    int index;
};
struct CompareSongs {
    bool operator()(const HeapSong& a, const HeapSong& b) const {
        if (a.popularity != b.popularity) {
            return a.popularity > b.popularity;
        }
        return a.index < b.index;
    }
};


vector<int> topKByPopularity(const vector<int>& scores, int k) {
    if (k<= 0 || scores.empty()) {
        return {};
    }

    int songCount = static_cast<int>(scores.size());
    if (k > songCount) {
        k = songCount;
    }
    priority_queue<HeapSong, vector<HeapSong>, CompareSongs> heap;
    for (int i=0; i < songCount; i++) {
        heap.push({scores[i], i});
        if (static_cast<int>(heap.size()) > k) {
            heap.pop();
        }
    }
    vector<int> result(k);
    for (int i = k-1; i >= 0; i--) {
        result[i] = heap.top().index;
        heap.pop();
    }
    return result;
}

vector<Song> rankByGenre(const vector<Song>& songs, const string& genre, int k) {
    vector<int> scores;
    vector<int> matchingIndices;
    for (int i=0; i < static_cast<int>(song.size()); i++) {
        if (songs[i].genre == genre) {
            scores.push_back(songs[i].popularityScore);
            matchingIndices.push_back(i);
        }
    }

    vector<Song> rankedSongs;
    for (int index : topKByPopularity(socres, k)) {
        rankedSongs.push_back(songs[matchingIndices[index]]);
    }
    return rankedSongs;
}