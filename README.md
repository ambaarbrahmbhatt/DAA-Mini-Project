# Dictionary Word Search System Using Binary Search

## Project Overview

The Dictionary Word Search System is a menu driven C++ application developed as a mini project for Design and Analysis of Algorithms (DAA). It uses the Binary Search algorithm to efficiently search for words in an alphabetically sorted dictionary and display their meanings.

The program demonstrates the step by step execution of binary search, counts the number of comparisons performed, and displays the time and space complexity of the algorithm.

## Features

1. Display all words and their meanings.
2. Search for a word using Binary Search.
3. Display each search step, including the low, high, and mid indices.
4. Count the number of comparisons performed.
5. Display the meaning of a word when it is found.
6. Show the best case, average case, and worst case time complexity.
7. Support case insensitive word searches.
8. Provide a simple menu driven console interface.

## Technologies Used

1. Programming Language: C++
2. Algorithm: Binary Search
3. Concepts: Sorting, vectors, structures, strings, and functions
4. Libraries: iostream, vector, string, algorithm, iomanip, and cctype

## How It Works

1. The program stores words and their meanings in a dictionary.
2. The dictionary is sorted alphabetically before the menu appears.
3. The user selects an operation from the menu.
4. When searching for a word, the program compares it with the middle word of the current search range.
5. If the target word is smaller, the search continues in the left half.
6. If the target word is larger, the search continues in the right half.
7. The process continues until the word is found or the search range becomes empty.
8. The program displays the search steps, the total number of comparisons, and the word meaning if a match is found.

## Menu Options

| Option | Description |
|---|---|
| 1 | Display Dictionary |
| 2 | Search a Word |
| 3 | View Complexity Analysis |
| 4 | Exit the Program |

## Algorithm Complexity Analysis

Let n represent the number of words in the dictionary.

| Case | Time Complexity | Explanation |
|---|---|---|
| Best Case | O(1) | The word is found at the first middle position. |
| Average Case | O(log n) | The search range is repeatedly divided in half. |
| Worst Case | O(log n) | The search continues until the word is found or the search range becomes empty. |
| Dictionary Storage | O(n) | Space is required to store all words and meanings. |
| Auxiliary Search Space | O(1) | A constant number of variables is used by the binary search algorithm. |

Note: The program also stores the search steps in a vector for displaying the execution trace. Including this trace, the additional space used by a search is O(log n).

## Requirements

1. A C++ compiler that supports C++11 or later.
2. A terminal or command prompt.
3. A code editor or IDE such as Visual Studio Code or Code::Blocks.

## How to Run the Project

### Step 1: Clone the Repository

```bash
git clone https://github.com/YOUR-USERNAME/YOUR-REPOSITORY.git
```

Replace YOUR-USERNAME and YOUR-REPOSITORY with your GitHub username and repository name.

### Step 2: Navigate to the Project Folder

```bash
cd YOUR-REPOSITORY
```

### Step 3: Compile the Program

Using the GNU C++ compiler:

```bash
g++ main.cpp -o dictionary
```

### Step 4: Run the Program

On Windows:

```bash
dictionary.exe
```

On Linux or macOS:

```bash
./dictionary
```

## Example Usage

Select option 2 from the menu and enter a word to search.

Example input:

```text
Enter the word to search: algorithm
```

The program displays the binary search steps, including the low, high, and mid indices, the middle word, and the decision made at each step.

If the word is found, the program displays the following information:

```text
WORD FOUND
Word    : algorithm
Meaning : A step-by-step procedure to solve a problem.
```

If the word is not present in the dictionary, the program displays a message indicating that the word was not found.

## Project Structure

```text
Dictionary-Word-Search/
    main.cpp
    README.md
```

## Learning Objectives

1. Understand the working principle of Binary Search.
2. Learn why sorting is necessary before applying Binary Search.
3. Analyze algorithm efficiency using Big O notation.
4. Track the steps performed during a search operation.
5. Apply C++ structures, vectors, strings, and functions.
6. Develop a menu driven console application.

## Future Enhancements

1. Add more words and meanings.
2. Allow users to add, edit, and delete dictionary entries.
3. Store dictionary data in external files.
4. Implement prefix based searching.
5. Develop a graphical user interface.
6. Compare Binary Search with Linear Search.

## Project Information

Project Title: Dictionary Word Search System Using Binary Search

Subject: Design and Analysis of Algorithms

Programming Language: C++

Project Type: Academic Mini Project
