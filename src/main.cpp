#include <iostream>
#include <random>

using namespace std;



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





class WordList {
    private:
    int length;
    vector<string> words;

    public:
    WordList() : length(0) {}

    void printList() const {
        if (length == 0) {
            cout << "Word list is empty." << endl;
            return;
        }
        for (int i = 0; i < length; i++) {
            cout << words[i] << endl;
        }
    }

    int getLength() const {
        return length;
    }

    void addWord(string word) {
        words.push_back(word);
        length++;
    }

    void removeWord(int index) {
        if (index < 0 || index >= length) {
            cout << "Error: Invalid index." << endl;
            return;
        }
        words.erase(words.begin() + index);
        length--;
    }

    vector<string> getWords() const {
        return words;
    }

    void clearList() {
        words.clear();
        length = 0;
    }
};





class Grid {
    private:
    int size;
    vector<vector<char>> matrix;
    int lastRow = 0;
    int lastCol = 0;

    public:
    Grid(int s) : size(s) {
        for (int i = 0; i < size; i++) {
            vector<char> row(size, ' ');
            matrix.push_back(row);
        }
    }

    int getSize() const {
        return size;
    }

    void display() const {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                cout << matrix[i][j] << " ";
            }
            cout << endl;
        }
    }

    void generateRand() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                matrix[i][j] = randlet();
            }
        }
    }

    bool roomForWord(int length, int row, int col, int dir) {
        // 1 = up, 2 = up-right, 3 = right, etc. clockwise
        int endRow = row;
        int endCol = col;

        switch (dir) {
            case 1: endRow -= length - 1; break;
            case 2: endRow -= length - 1; endCol += length - 1; break;
            case 3: endCol += length - 1; break;
            case 4: endRow += length - 1; endCol += length - 1; break;
            case 5: endRow += length - 1; break;
            case 6: endRow += length - 1; endCol -= length - 1; break;
            case 7: endCol -= length - 1; break;
            case 8: endRow -= length - 1; endCol -= length - 1; break;
            default: return false;
        }

        if (endRow < 0 || endRow >= size || endCol < 0 || endCol >= size) {
            return false;
        }
        return true;
    }

    void placeWord(string word, int row, int col, int dir) {
        // 1 = up, 2 = up-right, 3 = right, etc. clockwise
        int wordLength = word.length();
        if (!roomForWord(wordLength, row, col, dir)) {
            cout << "Error: Not enough room to place word." << endl;
            return;
        }

        char arr[wordLength];
        strcpy(arr, word.c_str());

        for (int i = 0; i < wordLength; i++) {
            switch (dir) {
                case 1: matrix[row - i][col] = arr[i]; break;
                case 2: matrix[row - i][col + i] = arr[i]; break;
                case 3: matrix[row][col + i] = arr[i]; break;
                case 4: matrix[row + i][col + i] = arr[i]; break;
                case 5: matrix[row + i][col] = arr[i]; break;
                case 6: matrix[row + i][col - i] = arr[i]; break;
                case 7: matrix[row][col - i] = arr[i]; break;
                case 8: matrix[row - i][col - i] = arr[i]; break;
            }
        }
        

    }

    void selectLetter(int row, int col) {

        bool allLower = true;
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (isupper(matrix[i][j])) {
                    allLower = false;
                    break;
                }
            }
        }

        if (!allLower && ((row - lastRow) * (row - lastRow) + (col - lastCol) * (col - lastCol)) > 2) {
            cout << "Error: Can only select adjacent letters." << endl;
            return;
        }

        if (row < 0 || row >= size || col < 0 || col >= size) {
            cout << "Error: Invalid coordinates." << endl;
            return;
        }
        matrix[row][col] = flipCase(matrix[row][col]);
        lastRow = row;
        lastCol = col;
    }

    void deselect() {
        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (isupper(matrix[i][j])) {
                    matrix[i][j] = tolower(matrix[i][j]);
                }
            }
        }
    }

};





int main() {
    Grid grid(6);
    grid.generateRand();
    grid.display();
    newLines(4);
    grid.placeWord("hello", 1, 1, 3);
    grid.display();
    newLines(4);
    grid.selectLetter(1, 1);
    grid.display();
    newLines(4);
    grid.selectLetter(1, 2);
    grid.display();
    newLines(4);
    grid.deselect();
    grid.display();

    WordList list;
    list.addWord("hello");
    list.addWord("world");
    list.addWord("test");
    list.printList();
    cout << "Length: " << list.getLength() << endl;
    list.removeWord(1);
    list.printList();
    cout << "Length: " << list.getLength() << endl;
    list.addWord("new");
    list.printList();
    cout << "Length: " << list.getLength() << endl;
    return 0;
}