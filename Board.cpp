#include <iostream>
#include <algorithm>
#include "Board.h"
#include "Hopper.h"
#include "Bug.h"

using namespace std;
//
// Created by biava on 26/04/2024.
//
Board::Board() {
    // Initialize cells grid
    cells.resize(10, vector<string>(10, "No bugs present"));
}

void Board::displayBugs(Bug *bug) {
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

    if (bug->getBugType() == "Crawler" || bug->getBugType() == "Bishop") {
        cout << bug->getId() << " " << bug->getBugType() << " (" << bug->getPosition().first << ","
             << bug->getPosition().second << ") " << direction << " " << bug->getSize() << " "
             << alive << endl;
    } else if (bug->getBugType() == "Hopper") {
        cout << bug->getId() << " " << bug->getBugType() << " (" << bug->getPosition().first << ","
             << bug->getPosition().second << ") " << direction << " " << bug->getSize() << " "
             << alive << " " << dynamic_cast<Hopper *>(bug)->getHopLength() << endl;
    }
}

void Board::findBug(int id) {

    for (auto bug : bugs_vector) {
        if (bug->getId() == id) {
            displayBugs(bug);
            return;
        }
    }
    cout << "Bug not found" << endl;
}

void Board::displayBugHistory() {
    for (auto bug : bugs_vector) {
        cout << "Bug " << bug->getId() << " history: ";
        for (auto path : bug->getPath()) {
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

void Board::displayCells() {
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

void Board::tapBoard() {
    //Start simulation
    //Move bugs
    move();
    //Fight bugs
    eat();

    // Display the board
    displayCells();
    // Display the bugs
    getBugs();
}

void Board::move() {
    //Move bugs
    for (auto bug : bugs_vector) {
        if (bug->isAlive()) {
            bug->move();
        }
    }
}

void Board::eat() {
    // Create vector that holds pointers to the bugs that are in the same position
    vector<Bug*> bugsOnCell;

    // Check cells for bugs in the same position
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            for (auto bug : bugs_vector) {
                if (bug->getPosition().first == i && bug->getPosition().second == j) {
                    if (bug->isAlive()) {
                        bugsOnCell.push_back(bug);
                    }
                }
            }

            // If there are more than one bug in the same position
            if (bugsOnCell.size() > 1) {
                // Sort the bugs by size using std::sort
                sort(bugsOnCell.begin(), bugsOnCell.end(), [](Bug *a, Bug *b) {
                    return a->getSize() > b->getSize();
                });

                // The biggest bug eats all other bugs
                for (size_t k = 1; k < bugsOnCell.size(); ++k) {
                    bugsOnCell[0]->setSize(bugsOnCell[0]->getSize() + bugsOnCell[k]->getSize());
                    bugsOnCell[k]->setAlive(false);
                    bugsOnCell[k]->setKillerId(bugsOnCell[0]->getId());
                }
            }

            // Clear the bugsOnCell vector for the next iteration
            bugsOnCell.clear();
        }
    }
}

void Board::addBug( Bug *bug) {
    bugs_vector.push_back(bug);
}

void Board::getBugs() {
    for (auto bug : bugs_vector) {
        displayBugs(bug);
    }
}

int Board::countBugs() {
    //return number of alive bugs
    int count = 0;
    for (auto bug : bugs_vector) {
        if (bug->isAlive()) {
            count++;
        }
    }
    return count;
}

vector<Bug *> Board::getBugsVector() {
    return bugs_vector;
}

void Board::clearVector() {
    bugs_vector.clear();
}