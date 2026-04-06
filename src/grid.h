#ifndef GRID_H
#define GRID_H

#include <iostream>
#include <random>
using namespace std;


class Grid {
    private:
    int size;
    vector<vector<char>> matrix;
    int lastRow = 0;
    int lastCol = 0;
    string selection = "";
    vector<vector<int>> space;

    public:
    Grid(int s);

    int getSize() const;

    string getSelection() const;

    void display() const;

    void generateRand();

    bool roomForWord(string word, int row, int col, int dir);

    void placeWord(string word, int row, int col, int dir);

    void selectLetter(int row, int col);

    void deselect();

};


#endif