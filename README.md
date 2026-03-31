# Word Search Puzzle Generator Final Project 

## Team Members
- Kayden Eishen  
- Ryan Lam  
- Dylan Patel  

---

## Project Overview
This project is a C++ word search puzzle generator that allows each user to create and play customized word search puzzles. First, the system generates a grid of random letters. Then, it replaces different sequences of letters with the user's provided words in different directions (horizontal, vertical, and diagonal). Finally,the system allows the users to check the words they've found by selecting the coordinates of the words.

The goal of this project is to use Object-Oriented Programming principles to create a functional and interactive Word Search Puzzle Generator.

---

## Main Functionalities
- `generateGrid()` - Generate a word search puzzle grid with randomly placed words
- `addWord()` - Add words to a customizable word list
- `placeWord()` – Randomly integrate the word list into the generated grid
- `displayGrid()` – Display the puzzle grid on the screen
- `checkWord()` – Allow the user to input guesses using coordinates
- `validateSelection()` – Check if the selected word is correct or not

---

## OOP Design Summary

### WordList Class
**Purpose:** Manages every words that is used in the puzzle  

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

### Game / Controller (Planned)
**Purpose:** Controls overall program flow and user interaction  

**Responsibilities:**
- Connects WordList and Grid classes  
- Handles user input 
- Controls menu options  


**Progress:** Not implemented yet

---


## Project Structure

- WordSearchProject/
- │
- ├── README.md
- ├── docs/
- │ └── System_Design_Overview.pdf
- ├── pseudocode/
- │ └── pseudocode.txt
- ├── src/
- │ ├── main.cpp
- │ ├── Grid.cpp
- │ ├── Grid.h
- │ ├── WordList.cpp
- │ ├── WordList.h
- │ └── Game.cpp (planned)
- └── images/
- └── system_diagram.png

---

## Current Progress 3/31/26 (Iteration #05)
- WordList class fully completed  
- Grid class fully implemented 
- Pseudocode completed for major functions 
- Game/menu input hasn't been incorporated yet  

Overall progress is approximately 75% complete.

---

## How to Compile and Run

g++ main.cpp Grid.cpp WordList.cpp -o wordsearch

### Compile

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
