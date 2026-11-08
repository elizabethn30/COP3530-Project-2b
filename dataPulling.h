#pragma once
#include <iostream>
#include <string>
#include <vector>
// #include <fstream>
using namespace std;

// All of the column names; currently take in all of the columns
// ,track_id,artists,album_name,track_name,popularity,duration_ms,explicit,danceability,energy,key,loudness,mode,speechiness,acousticness,instrumentalness,liveness,valence,tempo,time_signature,track_genre

class dataPulling {
private:
    int name;
public:
    dataPulling();
    void readFile();
    // vector<string> getDataset();

    // ~dataPulling();
};