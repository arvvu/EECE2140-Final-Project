#ifndef WORDLIST_H
#define WORDLIST_H

#include <iostream>
#include <random>
using namespace std;



class WordList {
    private:
    int length;
    vector<string> words;

    public:
    WordList() : length(0) {}

    void printList() const;

    int getLength() const;

    void addWord(string word);

    void removeWord(int index);

    vector<string> getWords() const;

    void clearList();
};

#endif