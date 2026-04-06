#include "wordList.h"





    
void WordList::printList() const {
    if (length == 0) {
        cout << "Word list is empty." << endl;
        return;
    }
    for (int i = 0; i < length; i++) {
        cout << words[i] << endl;
    }
}

int WordList::getLength() const {
    return length;
}

void WordList::addWord(string word) {
    words.push_back(word);
    length++;
}

void WordList::removeWord(int index) {
    if (index < 0 || index >= length) {
        cout << "Error: Invalid index." << endl;
        return;
    }
    words.erase(words.begin() + index);
    length--;
}

vector<string> WordList::getWords() const {
    return words;
}

void WordList::clearList() {
    words.clear();
    length = 0;
}
