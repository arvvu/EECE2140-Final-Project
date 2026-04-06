#include <iostream>
#include <random>
#include "wordList.h"
#include "grid.h"
#include "functions.h"
using namespace std;























int main() {
    bool exit = false;
    int selection;
    WordList wordList;
    while (!exit) {
        selection = 0;
        cout << "Welcome to the Word Search Game!" << endl;
        cout << "Enter a listed number to select an option, or any other int to exit." << endl;
        cout << "(1) Play game with selected words" << endl;
        cout << "(2) Add word to list" << endl;
        cout << "(3) Clear word list" << endl;
        cout << "(4) Display word list" << endl;
        cout << "(5) How to play" << endl;
        cout << "Enter: ";
        cin >> selection;
        
        newLines(40);

        switch (selection) {
            case 1: {
                newLines(40);
                if (wordList.getLength() == 0) {
                    cout << "Word list is empty. Please add words before playing." << endl;
                    cout << "Enter anything to return to menu: ";
                    string temp;
                    cin >> temp;
                    break;
                }
                cout << "Enter grid size (min 5, max 50): ";
                int size;
                cin >> size;
                if (size < 05 || size > 50) {
                    cout << "Error: Grid size must be between 5 and 50." << endl;
                    cout << "Enter anything to return to menu: ";
                    string temp;
                    cin >> temp;
                    break;
                } 
                Grid gameGrid(size);
                gameSetup(wordList, gameGrid);
                cout << "NOTE: If game setup was not successful, it's likely because the grid size was too small, there were " <<
                endl << "too many words, or some words were too long. Enter 0 to return to menu and try different parameters, " <<
                endl << "or anything else to continue: ";
                string choice;
                cin >> choice;
                if (choice == "0") {
                    break;
                }

                playGame(wordList, gameGrid);
                
                break;
                


            }
            case 2: {
                newLines(40);
                string word;
                cout << "Enter word to add (must be all letters): ";
                cin >> word;
                for (char c : word) {
                    if (!isalpha(c)) {
                        cout << "Error: Word must only contain letters." << endl;
                        word = "";
                        break;
                    }
                }
                if (word != "") {
                    for (char &c : word) {
                        c = tolower(c);
                    }
                    wordList.addWord(word);
                    cout << "Word added successfully!" << endl;
                }
                cout << "Enter anything to return to menu: ";
                string temp;
                cin >> temp;
                break;
            }
            case 3: {
                newLines(40);
                cout << "Are you sure you want to clear the word list? (y/n): ";
                string yn;
                cin >> yn;
                if (yn == "y" || yn == "Y") {
                    wordList.clearList();
                    cout << "Word list cleared successfully!" << endl;
                }
                else if (yn == "n" || yn == "N") {
                    cout << "Word list not cleared." << endl;
                }
                else {
                    cout << "Invalid input. Word list not cleared." << endl;
                }
                cout << "Enter anything to return to menu: ";
                string temp;
                cin >> temp;
                break;
            }
            case 4: {
                newLines(40);
                wordList.printList();
                cout << "Enter anything to return to menu: ";
                string temp;
                cin >> temp;
                break;
            }
            case 5: {
                newLines(40);
                cout << "Edit the word list to customize the words that will appear in the game." << endl;
                cout << "Upon beginning the game, a grid will be generated with the words hidden in it." << endl;
                cout << "To select a letter, enter its coordinates in the format 'col row' (without quotes)." << endl;
                cout << "For example, the top left letter would be '1 1', the letter to its right would be '2 1', and so on." << endl;
                cout << "Selected letters will be capitalized. You can only select adjacent letters, and" << endl;
                cout << "selecting the last letter to complete a word will remove that word from the list." << endl;
                cout << "Find all words to win the game!" << endl << endl;
                cout << "Enter anything to return to menu: ";
                string temp;
                cin >> temp;
                break;
            }
            default: {exit = true; break;}
        }

        newLines(40);
    }
}