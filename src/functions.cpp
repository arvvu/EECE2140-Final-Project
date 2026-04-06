#include "functions.h"

char flipCase(char c) {
    if (isupper(c)) {
        return tolower(c);
    }
    else if (islower(c)) {
        return toupper(c);
    }
    else {
        return c;
    }
    
}

void newLines(int n) {
    for (int i = 0; i < n; i++) {
        cout << endl;
    }
}

char randlet() {
    char c[26] = {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm',
                'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> dis(0, 25);
    return c[dis(gen)];
}

void gameSetup(WordList& wordList, Grid& grid) {
    vector<string> words = wordList.getWords();
    int choice = 0;
    while (choice == 0) {
        grid.generateRand();
        bool allSuccessful = true;
        for (int i = 0; i < words.size(); i++) {
            bool placed = false;


            for (int j = 0; j < 200 && !placed; j++) {
                int row = rand() % grid.getSize();
                int col = rand() % grid.getSize();
                int dir = (rand() % 8) + 1;
                if (grid.roomForWord(words[i], row, col, dir)) {
                    grid.placeWord(words[i], row, col, dir);
                    placed = true;
                }
            }

            if (!placed) {
                cout << "Error: Could not place word '" << words[i] << "' on the grid." << endl;
                allSuccessful = false;
            }

        }
        if (!allSuccessful) {
            cout << "Game setup could not be completed successfully. Enter 0 to try again or any other int to continue with current setup: ";
            
            cin >> choice;
        }
        else {
            cout << "Game setup completed successfully!" << endl;
            choice = 1;
        }
    }
}

void playGame(WordList& wordList, Grid& grid) {
    bool playing = true;
    string temp;
    int coords[2];
    int result;
    while (playing) {
        newLines(40);
        grid.display();
        cout << endl;
        cout << "Words to find: " << endl;
        wordList.printList();
        cout << endl;
        cout << "Current selection: " << grid.getSelection() << endl;
        cout << endl;
        cout << "Enter coordinates to select letter (col row), or 0 to deselect, or -1 to exit to menu: ";

        
        cin >> coords[0];
        if (coords[0] == 0) {
            grid.deselect();
            continue;
        }
        else if (coords[0] == -1) {
            result = 0;
            playing = false;
            break;
        }
        else {
            cin >> coords[1];
            grid.selectLetter(coords[1] - 1, coords[0] - 1);
            string selection = grid.getSelection();
            vector<string> words = wordList.getWords();
            for (int i = 0; i < words.size(); i++) {
                if (selection == words[i]) {
                    wordList.removeWord(i);
                    grid.deselect();
                }
            }
        }

        if (wordList.getLength() == 0) {
            result = 1;
            playing = 0;
        }


    }

    newLines(40);
    if (result == 1) {
        cout << "Congratulations! You found all the words! Enter anything to return to the menu." << endl;
        cin >> temp;
    }
}