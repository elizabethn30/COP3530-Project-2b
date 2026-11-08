#pragma once
#include "song.h"
#include <vector>
using namespace std;

vector<int> topKByPopularity(const vector<int>& scores, int k);

vector<Song> rankByGenre(const vector<Song>& songs, const string& genre, int k);