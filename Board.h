//
// Created by biava on 26/04/2024.
//

#ifndef CA2BIANCAVALICEC_BOARD_H
#define CA2BIANCAVALICEC_BOARD_H

#include <vector>
#include "Bug.h"

class Board {
private:
    vector<Bug *> bugs_vector; // Vector of bugs
    vector<vector<string>> cells; // Grid of cells

public:
    Board(); // Constructor// Read bugs from file
    static void displayBugs(Bug *bug);// Display bugs
    void findBug(int id); // Find bug by ID
    void displayBugHistory(); // Display bug history
    void displayCells(); // Display cells
    void tapBoard(); // Start simulation
    void addBug(Bug *bug); // Add bug
    void getBugs(); // Get bugs
    int countBugs(); // Count bugs (alive)
    vector<Bug *> getBugsVector(); // Get bugs vector
    void clearVector(); // Clear bugs vector

private:
    void move(); // Move bugs
    void eat(); // Fight bugs
};

#endif //CA2BIANCAVALICEC_BOARD_H
