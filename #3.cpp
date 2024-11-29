#include <iostream>
#include <fstream>
#include <map>
#include <vector>
#include <string>
using namespace std;

enum Score
{
    Unsatisfactorily = 2,
    Satisfactorily,
    Good,
    Excellent
};

struct Student
{
    string Name;
    int Year;
    map<string, Score> RecordBook;
};

using Groups = map<string, vector<Student>>;

void saveToFile(const string& filename, const Groups& groups) {
    ofstream outFile(filename);
    for (const auto& gr : groups) {
        const string& groupName = gr.first;
        const vector<Student>& students = gr.second;
        outFile << groupName << endl; 
        outFile << students.size() << endl;
        for (const Student& student : students) {
            outFile << student.Name << endl;
            outFile << student.Year << endl;
            outFile << student.RecordBook.size() << endl;
            for (const auto& rec : student.RecordBook) {
                outFile << rec.first << ' ' << (rec.second) << endl;
            }
        }
    }
    outFile.close();
}
void loadFromFile(const string& filename, Groups& outGroups)
{
    ifstream inFile(filename);

    string groupName;
    while (getline(inFile, groupName)) {
        
        size_t numStudents;
        inFile >> numStudents;
        inFile.ignore(); 

        vector<Student> students;
        students.reserve(numStudents);

        for (size_t i = 0; i < numStudents; ++i) {
            Student student;
            getline(inFile, student.Name);
            inFile >> student.Year;
            inFile.ignore(); 
            size_t numRec;
            inFile >> numRec;
            inFile.ignore(); 
            for (size_t j = 0; j < numRec; ++j) {
                string subject;
                int scoreInt;
                getline(inFile, subject);
                inFile >> scoreInt;
                inFile.ignore(); 
                student.RecordBook[subject] = static_cast<Score>(scoreInt);
            }
            students.push_back(student);
        }
        outGroups[groupName] = students;
    }
    inFile.close();
}
