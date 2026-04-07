# Word Search Puzzle Generator Final Project 

## Team Members
- Kayden Eishen  
- Ryan Lam  
- Dylan Patel  

---

## Project Overview
This project is a C++ word search puzzle generator that allows the user to create and play customized word search puzzles. First, the system generates a grid of random letters. Then, it replaces different sequences of letters with the user's provided words in different directions (horizontal, vertical, and diagonal). Finally, the system allows users to find words in the grid by selecting the coordinates of each letter in the grid.

The goal of this project is to use Object-Oriented Programming principles to create a functional and interactive Word Search Puzzle Generator.

---

## Main Functionalities
- `generateGrid()` - Generate grid of random letters
- `addWord()` - Add words to a customizable word list
- `roomForWord()` - Check if there is room on the grid for a word to be placed in a certain spot
- `placeWord()` – Place a word in a certain spot on the grid with a certain direction
- `displayGrid()` – Display the puzzle grid on the screen
- `selectLetter()` – Capitalize a letter on the grid and add it to a string of all letters selected

---

## OOP Design Summary

### WordList Class
**Purpose:** Manages the words that will be used in the puzzle  

**Responsibilities:**
- Store a list of words using a vector  
- Add and remove words  
- Returns the list of words for puzzle generation

**Progress:** Completed  

---

### Grid Class
**Purpose:** Handles the creation and management of the puzzle grid  

**Responsibilities:**
- Stores the grid as a 2D vector of characters  
- Generates a grid of random letters  
- Places words into the grid in different directions  
- Displays the grid to the user  

**Progress:** Completed

---

### Game / Controller
**Purpose:** Controls overall program flow and user interaction  

**Responsibilities:**
- gameSetup() sets up a grid containing all of the words in a given word list  
- playGame() runs a loop that lets the user "play" the word search, selecting and finding words until none remain 


**Progress:** Completed

---


## Project Structure

- WordSearchProject/
- │
- ├── pseudocode/
- │ └── pseudocode.txt
- ├── src/
- │ ├── main.cpp
- │ ├── grid.cpp
- │ ├── grid.h
- │ ├── wordList.cpp
- │ ├── wordList.h
- │ ├── functions.cpp
- │ └── functions.h
- └── README.md

---

## Current Progress 3/31/26 (Iteration #05)
- WordList class fully completed  
- Grid class fully implemented 
- Pseudocode completed for major functions 
- Game/menu input hasn't been incorporated yet  

Overall progress is approximately 75% complete.

## Current Porgress 4/7/26 (Final Submission)
- The game is fully functional and user input is supported

Overall progress is 100% complete.

---

## How to Compile and Run

g++ main.cpp grid.cpp wordList.cpp functions.cpp -o wordsearch

### Run

./wordsearch

---

## Project Goals
- Build fully functional word search puzzle generator
- Demonstrate understanding of key OOP concepts in C++
- Develop clean and expandable code
- Practice professional Computer Engineering standards using GitHub
---

## GitHub Repository Purpose
This repository is used to:
- Track the project's progress using commits
- Collaborate as a team using GitHub
- Store all source code and documentation
