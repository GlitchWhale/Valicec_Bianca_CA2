#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"

using namespace std;

void readFromFile();
void parseLine(const string &strline);
void printBug(Bug *bug);
void findBug();

vector<Bug *> bugs_vector;

int main() {
    readFromFile();

    //menu that takes the user input and runs appropriate function
    while (true) {
        cout << "1. Display bugs" << endl;
        cout << "2. Find bug" << endl;
        cout << "3. Move bugs" << endl;
        cout << "4. Exit" << endl;
        int choice;
        cin >> choice;

        if (choice == 1) {
            for (auto bug: bugs_vector) {
                printBug(bug);
            }
        }
        else if (choice == 2){
            findBug();
        }
        else if (choice == 3) {
            for (auto bug: bugs_vector) {
                bug->move();
            }
        } else if (choice == 4) {
            break;
        } else {
            cout << "Invalid choice" << endl;
        }
    }

    return 0;
}

void readFromFile() {
    ifstream inFileStream("bugs.txt");

    if (inFileStream) {
        string line;

        while (getline(inFileStream, line)) {
            parseLine(line);
        }

        inFileStream.close();
    } else {
        cout << "Error opening file" << endl;
    }
}

void parseLine(const string &strline) {
    stringstream strSteam(strline);

    const char delim = ';';
    string type;
    getline(strSteam, type, delim);
    string temp;

    try {
        if (type == "C") {
            int id;
            pair<int, int> position;
            int direction;
            int size;
            getline(strSteam, temp, delim);
            id = stoi(temp);
            getline(strSteam, temp, delim);
            position.first = stoi(temp);
            getline(strSteam, temp, delim);
            position.second = stoi(temp);
            getline(strSteam, temp, delim);
            direction = stoi(temp);
            getline(strSteam, temp, delim);
            size = stoi(temp);
            auto *crawler = new Crawler(id, position, direction, size);
            bugs_vector.push_back(crawler);
        } else if (type == "H") {
            int id;
            pair<int, int> position;
            int direction;
            int size;
            int hopLength;
            getline(strSteam, temp, delim);
            id = stoi(temp);
            getline(strSteam, temp, delim);
            position.first = stoi(temp);
            getline(strSteam, temp, delim);
            position.second = stoi(temp);
            getline(strSteam, temp, delim);
            direction = stoi(temp);
            getline(strSteam, temp, delim);
            size = stoi(temp);
            getline(strSteam, temp, delim);
            hopLength = stoi(temp);
            auto *hopper = new Hopper(id, position, direction, size, hopLength);
            bugs_vector.push_back(hopper);
        } else {
            cout << "Invalid type" << endl;
        }
    }
    catch (std::invalid_argument const &e) {
        cout << "Invalid argument" << endl;
    }
    catch (std::out_of_range const &e) {
        cout << "Out of range" << endl;
    }
    catch (...) {
        cout << "Error" << endl;
    }
}

void printBug(Bug *bug){
        //set the direction to a string
        string direction;
        if (bug->getDirection() == 1) {
            direction = "North";
        } else if (bug->getDirection() == 2) {
            direction = "East";
        } else if (bug->getDirection() == 3) {
            direction = "South";
        } else if (bug->getDirection() == 4) {
            direction = "West";
        }

        //set alive to a string say dead or alive
        string alive;
        if (bug->isAlive()) {
            alive = "Alive";
        } else {
            alive = "Dead";
        }

        if (bug->getBugType() == "Crawler") {
            cout << bug->getId() << " " << bug->getBugType() << " (" << bug->getPosition().first << ","
                 << bug->getPosition().second << ") " << direction << " " << bug->getSize() << " "
                 << alive << endl;
        } else if (bug->getBugType() == "Hopper") {
            cout << bug->getId() << " " << bug->getBugType() << " (" << bug->getPosition().first << ","
                 << bug->getPosition().second << ") " << direction << " " << bug->getSize() << " "
                 << alive << " " << dynamic_cast<Hopper *>(bug)->getHopLength() << endl;
        }
}

void findBug() {
    int id;
    cout << "Enter bug id: ";
    cin >> id;

    for (auto bug: bugs_vector) {
        if (bug->getId() == id) {
            printBug(bug);
            return;
        }
    }

    cout << "Bug " << id << " not found" << endl;
}