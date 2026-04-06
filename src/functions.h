#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include <iostream>
#include <random>
#include "grid.h"
#include "wordList.h"
using namespace std;

char flipCase(char c);

void newLines(int n);

char randlet();

void gameSetup(WordList& wordList, Grid& grid);

void playGame(WordList& wordList, Grid& grid);

#endif