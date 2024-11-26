#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

void saveToFile(const string& filename, const vector<string>& data) {
    ofstream file(filename);
    for (const auto& word : data) file << word << endl;
    file.close();
}

void loadFromFile(const string& filename, vector<string>& outData) {
    ifstream file(filename);
    string line;
    while (getline(file, line)) outData.push_back(line);
    file.close();
}
