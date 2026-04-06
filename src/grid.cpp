#include "grid.h"
#include "functions.h"






Grid::Grid(int s) : size(s) {
    for (int i = 0; i < size; i++) {
        vector<char> row(size, ' ');
        matrix.push_back(row);

        vector<int> spaceRow(size, 0);
        space.push_back(spaceRow);
    }
}

int Grid::getSize() const {
    return size;
}

string Grid::getSelection() const {
    return selection;
}

void Grid::display() const {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

void Grid::generateRand() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            matrix[i][j] = randlet();
        }
    }
}

bool Grid::roomForWord(string word, int row, int col, int dir) {
    // 1 = up, 2 = up-right, 3 = right, etc. clockwise
    int endRow = row;
    int endCol = col;
    int wordLength = word.length();

    switch (dir) {
        case 1: endRow -= wordLength - 1; break;
        case 2: endRow -= wordLength - 1; endCol += wordLength - 1; break;
        case 3: endCol += wordLength - 1; break;
        case 4: endRow += wordLength - 1; endCol += wordLength - 1; break;
        case 5: endRow += wordLength - 1; break;
        case 6: endRow += wordLength - 1; endCol -= wordLength - 1; break;
        case 7: endCol -= wordLength - 1; break;
        case 8: endRow -= wordLength - 1; endCol -= wordLength - 1; break;
        default: return false;
    }

    if (endRow < 0 || endRow >= size || endCol < 0 || endCol >= size) {
        return false;
    }

    for (int i = 0; i < wordLength; i++) {
        int c;
        switch (dir) {
            case 1: c = space[row - i][col];     break;
            case 2: c = space[row - i][col + i]; break;
            case 3: c = space[row][col + i];     break;
            case 4: c = space[row + i][col + i]; break;
            case 5: c = space[row + i][col];     break;
            case 6: c = space[row + i][col - i]; break;
            case 7: c = space[row][col - i];     break;
            case 8: c = space[row - i][col - i]; break;
        }
        if (c == 1) {
            return false;
        }
    }

    return true;
}

void Grid::placeWord(string word, int row, int col, int dir) {
    // 1 = up, 2 = up-right, 3 = right, etc. clockwise
    int wordLength = word.length();
    if (!roomForWord(word, row, col, dir)) {
        cout << "Error: Not enough room to place word." << endl;
        return;
    }

    char arr[wordLength];
    strcpy(arr, word.c_str());

    for (int i = 0; i < wordLength; i++) {
        switch (dir) {
            case 1: matrix[row - i][col] = arr[i];     space[row - i][col] = 1;     break;
            case 2: matrix[row - i][col + i] = arr[i]; space[row - i][col + i] = 1; break;
            case 3: matrix[row][col + i] = arr[i];     space[row][col + i] = 1;     break;
            case 4: matrix[row + i][col + i] = arr[i]; space[row + i][col + i] = 1; break;
            case 5: matrix[row + i][col] = arr[i];     space[row + i][col] = 1;     break;
            case 6: matrix[row + i][col - i] = arr[i]; space[row + i][col - i] = 1; break;
            case 7: matrix[row][col - i] = arr[i];     space[row][col - i] = 1;     break;
            case 8: matrix[row - i][col - i] = arr[i]; space[row - i][col - i] = 1; break;
        }
    }
    cout << "Word placed successfully!" << endl;
    

}

void Grid::selectLetter(int row, int col) {

    bool allLower = true;
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (isupper(matrix[i][j])) {
                allLower = false;
                break;
            }
        }
    }

    if (!allLower && (((row - lastRow) * (row - lastRow) + (col - lastCol) * (col - lastCol)) > 2 || (row == lastRow && col == lastCol))) {
        cout << "Error: Can only select adjacent letters." << endl;
        return;
    }

    if (row < 0 || row >= size || col < 0 || col >= size) {
        cout << "Error: Invalid coordinates." << endl;
        return;
    }
    selection += matrix[row][col];
    matrix[row][col] = flipCase(matrix[row][col]);
    lastRow = row;
    lastCol = col;
}

void Grid::deselect() {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            if (isupper(matrix[i][j])) {
                matrix[i][j] = tolower(matrix[i][j]);
            }
        }
    }
    selection = "";
}

