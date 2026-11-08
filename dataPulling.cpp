#include "dataPulling.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

dataPulling::dataPulling() {}

//Splits one row of text into columns.
static bool readRow(istream & file, vector<string>& columns) {
    columns.clear();
    string text;
    bool inQuotes = false;
    char ch;

    while (file.get(ch)) {
        if (ch == '"') {
            if (inQuotes && file.peek() == '"') {
                file.get();
                text += '"';
            } else {
                inQuotes = !inQuotes;
            }
        } else if (ch == ',' && !inQuotes) {
            //finishes with column
            coulumns.push_back(text);
            text.clear();
        } else if (ch == "\n" && !inQuotes) {
            //finishes reading row
            columns.push_back(text);
            return true;
        } else if (ch != "\r") {
            text += ch;
        }
    }
    if (inQuotes || (columns.empty() && text.empty())) {
        return false;
    }
    columns.push_back(text);
    return true;
}

vector<Song> dataPulling::readFile() {
    ifstream musicData("dataset.csv");
    //vector<string> dataset;

    //musicData.open("dataset.csv");
    if (!musicData.is_open()) {
        cout << "Error opening file" << endl;
        return {};
    }

    vector<Song> songs;
    vector<string> columns;
    readRow(musicData, columns);

    while (readRow(musicData, columns)) {
        if (columns.size() != 21) {
            continue;
        }
        const string& score = columns [5];
        if (score.empty() || score.size() > 3 || score.find_first_not_of("0123456789") != string::npos) {
            continue;
        }
        int popularity = stoi(score);
        if (popularity > 100) {
            continue;
        }
        Song song;
        song.id = columns [1];
        song.artist = columns[2];
        song.title = columns[4];
        song.popularityScore = popularity;
        songs. genre = columns[20];
        songs.push_back(song);
    }

    return songs;

    //string datapoints;
    //while (getline(musicData, datapoints)) {
    //    dataset.push_back(datapoints);
    //}
    // cout << "hello world" << endl;
    // cout << dataset.size() << endl;
    //cout << dataset[0] << endl;
    //cout << dataset[1] << endl;

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