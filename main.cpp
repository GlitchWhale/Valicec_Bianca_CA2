#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Bug.h"

using namespace std;

void readFromFile();
void parseLine(const string& strline);

int main() {
    vector<Bug*> bugs_vector;
}

void readFromFile(){
    ifstream inFileStream("bugs.txt");

    if(inFileStream.good()){
        string line;

        while(getline(inFileStream, line)){
            parseLine(line);
        }

        inFileStream.close();
    }
    else{
        cout << "Error opening file" << endl;
    }
}

void parseLine(const string& strline){
    stringstream strSteam(strline);

    const char delim = ';';
    string type;
}