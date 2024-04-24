#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <sstream>
#include <algorithm>
#include <thread>
#include "Bug.h"
#include "Crawler.h"
#include "Hopper.h"
#include "Bishop.h"

using namespace std;

void readFromFile();

void parseLine(const string &strline);

void printBug(Bug *bug);

void findBug();

void bugHistory();

void displayCells();

void fight();

void writeFile();

vector<Bug *> bugs_vector;

int main() {
    readFromFile();

    while (true) {
        cout << "0. Exit" << endl;
        cout << "1. Display bugs" << endl;
        cout << "2. Find bug" << endl;
        cout << "3. Bug history" << endl;
        cout << "4. Display cells" << endl;
        cout << "5. Tap board" << endl;

        int choice;
        cin >> choice;

        switch (choice) {
            case 0:
                return 0; // Exit the program
            case 1:
                for (auto bug: bugs_vector) {
                    printBug(bug);
                }
                break;
            case 2:
                findBug();
                break;
            case 3:
                bugHistory();
                break;
            case 4:
                displayCells();
                break;
            case 5:
                // Start simulation
                while (std::count_if(bugs_vector.begin(), bugs_vector.end(), [](Bug *bug) { return bug->isAlive(); }) !=
                       1) {
                    // Perform bug movements
                    for (auto bug: bugs_vector) {
                        if (bug->isAlive()) {
                            bug->move();
                        }
                    }

                    // Fight bugs
                    fight();

                    // Display bugs and cells
                    displayCells();
                    for (auto bug: bugs_vector) {
                        printBug(bug);
                    }

                    // Wait for one second before the next simulation step
                    std::this_thread::sleep_for(std::chrono::seconds(1));
                }

                // Write endgame history
                writeFile();

                return 0; // Exit after simulation ends
            default:
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
        } else if (type == "B") {
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
            auto *bishop = new Bishop(id, position, direction, size);
            bugs_vector.push_back(bishop);
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

void printBug(Bug *bug) {
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
    } else if (bug->getBugType() == "Bishop") {
        cout << bug->getId() << " " << bug->getBugType() << " (" << bug->getPosition().first << ","
             << bug->getPosition().second << ") " << direction << " " << bug->getSize() << " "
             << alive << endl;
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

void bugHistory() {
    for (auto bug: bugs_vector) {
        cout << bug->getId() << " " << bug->getBugType() << " path: ";
        for (auto path: bug->getPath()) {
            cout << "(" << path.first << "," << path.second << ") ";
        }
        //checks to see if the bug is alive or dead
        if (bug->isAlive()) {
            cout << "Alive!" << endl;
        } else {
            cout << "Died by bug " << bug->getKillerId() << endl;
        }


        cout << endl;
    }
}

void displayCells() {
    //Display all cells in sequence, and the name and id of all bugs currently occupying each cell.
    //If no bugs are present, display “No bugs present”.
    //Display the type and id

    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << "(" << i << "," << j << ") ";
            bool bugPresent = false;
            for (auto bug: bugs_vector) {
                if (bug->getPosition().first == i && bug->getPosition().second == j) {
                    cout << bug->getBugType() << " " << bug->getId() << " ";
                    bugPresent = true;
                }
            }
            if (!bugPresent) {
                cout << "No bugs present";
            }
            cout << endl;
        }
    }
}

void fight() {
    //Implement functionality that will cause bugs that land on the same cell to fight. This will happen
    //after a round of moves has taken place – invoked by menu option 4. ( Tap ….). The biggest bug in
    //the cell will eat all other bugs, and will grow by the sum of the sizes of the bugs it eats. The eaten
    //bugs will be marked as dead (‘alive=false’). We can keep ‘tapping’ the bug board until all the bugs
    //are dead except one – the Last Bug Standing. Two or more bugs equal in size won’t be able to
    //overcome each other so the winner is resolved at random.

    //check if there are bugs on the same cell
    for (int i = 0; i < 10; ++i) {
        for (int j = 0; j < 10; ++j) {
            vector<Bug *> bugsOnCell;
            for (auto bug: bugs_vector) {
                if (bug->getPosition().first == i && bug->getPosition().second == j) {
                    bugsOnCell.push_back(bug);
                }
            }

            if (bugsOnCell.size() > 1) {
                //sort the bugs by size
                sort(bugsOnCell.begin(), bugsOnCell.end(), [](Bug *a, Bug *b) {
                    return a->getSize() > b->getSize();
                });

                //the biggest bug eats all other bugs
                for (int k = 1; k < bugsOnCell.size(); ++k) {
                    bugsOnCell[0]->setSize(bugsOnCell[0]->getSize() + bugsOnCell[k]->getSize());
                    bugsOnCell[k]->setAlive(false);
                    bugsOnCell[k]->setKillerId(bugsOnCell[0]->getId());
                }
            }
        }
    }
}

//write to endgamehistory file and display every bugs history and the winner
void writeFile() {
    ofstream outFileStream("endgamehistory.txt");

    if (outFileStream) {

        outFileStream << "Endgame history" << endl;

        //write the history of each bug
        for (auto bug: bugs_vector) {
            outFileStream << bug->getId() << " " << bug->getBugType() << " path: ";
            for (auto path: bug->getPath()) {
                outFileStream << "(" << path.first << "," << path.second << ") ";
            }
            if (bug->isAlive()) {
                outFileStream << "Alive!" << endl;
            } else {
                outFileStream << "Died by bug " << bug->getKillerId() << endl;
            }
        }

        //find the last bug standing
        for (auto bug: bugs_vector) {
            if (bug->isAlive()) {
                outFileStream << "Last bug standing: " << bug->getId() << " " << bug->getBugType() << endl;
            }
        }

        outFileStream.close();
    } else {
        cout << "Error opening file" << endl;
    }
}