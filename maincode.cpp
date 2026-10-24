
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <iomanip>
#include <cctype>

using namespace std;

struct Word {
    string word;
    string meaning;
};

struct Step {
    int low, high, mid;
    string middleWord;
    string decision;
};

vector<Word> dictionary = {
    {"algorithm", "A step-by-step procedure to solve a problem."},
    {"apple", "A fruit that is usually red, green, or yellow."},
    {"array", "A collection of elements stored in sequence."},
    {"binary", "A number system that uses 0 and 1."},
    {"compiler", "A program that translates source code into machine code."},
    {"computer", "An electronic device that processes data."},
    {"data", "Facts or information used for processing."},
    {"database", "An organized collection of data."},
    {"debugging", "The process of finding and fixing program errors."},
    {"dictionary", "A collection of words and their meanings."},
    {"function", "A reusable block of code that performs a task."},
    {"graph", "A structure made of vertices and edges."},
    {"hardware", "The physical components of a computer."},
    {"loop", "A programming structure that repeats instructions."},
    {"memory", "The storage used to hold data and instructions."},
    {"network", "A group of connected computers or devices."},
    {"operator", "A symbol that performs an operation on values."},
    {"program", "A set of instructions executed by a computer."},
    {"recursion", "A technique in which a function calls itself."},
    {"search", "The process of finding an item in a collection."}
};


string toLowerCase(string s) {
    for (char &c : s) {
        c = static_cast<char>(
            tolower(static_cast<unsigned char>(c))
        );
    }
    return s;
}

void showHeader() {
    cout << "\n";
    cout << "===============================================\n";
    cout << "       DICTIONARY WORD SEARCH SYSTEM\n";
    cout << "       DAA MINI PROJECT - BINARY SEARCH\n";
    cout << "===============================================\n";
}

void showDictionary() {
    cout << "\n--------------- DICTIONARY -------------------\n";

    for (size_t i = 0; i < dictionary.size(); i++) {
        cout << left << setw(3) << i + 1
             << setw(15) << dictionary[i].word
             << dictionary[i].meaning << "\n";
    }

    cout << "-----------------------------------------------\n";
    cout << "Total words: " << dictionary.size() << "\n";
}

void searchWord() {
    string target;

    cout << "\nEnter the word to search: ";
    cin >> target;

    target = toLowerCase(target);

    int low = 0;
    int high = static_cast<int>(dictionary.size()) - 1;
    int comparisons = 0;
    bool found = false;

    vector<Step> steps;

    cout << "\n============== BINARY SEARCH STEPS ==============\n";
    cout << left
         << setw(7) << "Step"
         << setw(7) << "Low"
         << setw(7) << "High"
         << setw(7) << "Mid"
         << setw(16) << "Middle Word"
         << "Decision\n";

    cout << "-------------------------------------------------\n";

    while (low <= high) {
        int mid = low + (high - low) / 2;

        comparisons++;

        string middle = dictionary[mid].word;
        string decision;

        if (target == middle) {
            decision = "Word found!";
            steps.push_back({low, high, mid, middle, decision});

            cout << left
                 << setw(7) << steps.size()
                 << setw(7) << low
                 << setw(7) << high
                 << setw(7) << mid
                 << setw(16) << middle
                 << decision << "\n";

            found = true;
            break;
        }
        else if (target < middle) {
            decision = "Search left half";

            steps.push_back({low, high, mid, middle, decision});

            cout << left
                 << setw(7) << steps.size()
                 << setw(7) << low
                 << setw(7) << high
                 << setw(7) << mid
                 << setw(16) << middle
                 << decision << "\n";

            high = mid - 1;
        }
        else {
            decision = "Search right half";

            steps.push_back({low, high, mid, middle, decision});

            cout << left
                 << setw(7) << steps.size()
                 << setw(7) << low
                 << setw(7) << high
                 << setw(7) << mid
                 << setw(16) << middle
                 << decision << "\n";

            low = mid + 1;
        }
    }

    cout << "-------------------------------------------------\n";
    cout << "Total comparisons: " << comparisons << "\n";

    if (found) {
        cout << "\n                 WORD FOUND\n";
        cout << "Word    : " << dictionary[steps.back().mid].word << "\n";
        cout << "Meaning : "
             << dictionary[steps.back().mid].meaning << "\n";
    } else {
        cout << "\nSorry! The word was not found in the dictionary.\n";
    }

    cout << "=================================================\n";
}

void showComplexity() {
    cout << "\n------------ COMPLEXITY ANALYSIS ---------------\n";
    cout << "Best-case time complexity    : O(1)\n";
    cout << "Average-case time complexity : O(log n)\n";
    cout << "Worst-case time complexity   : O(log n)\n";
    cout << "Dictionary storage           : O(n)\n";
    cout << "Search auxiliary space       : O(1)\n";
    cout << "------------------------------------------------\n";
}

int main() {
    // Ensure the dictionary is alphabetically sorted.
    sort(dictionary.begin(), dictionary.end(),
         [](const Word &a, const Word &b) {
             return a.word < b.word;
         });

    int choice;

    do {
        showHeader();

        cout << "1. Display Dictionary\n";
        cout << "2. Search a Word\n";
        cout << "3. View Complexity Analysis\n";
        cout << "4. Exit\n";

        cout << "\nEnter your choice: ";

        if (!(cin >> choice)) {
            cout << "\nInvalid input. Please enter a number.\n";
            return 0;
        }

        switch (choice) {
            case 1:
                showDictionary();
                break;

            case 2:
                searchWord();
                break;

            case 3:
                showComplexity();
                break;

            case 4:
                cout << "\nThank you for using Dictionary Search!\n";
                cout << "Project completed successfully.\n";
                break;

            default:
                cout << "\nInvalid choice. Please select 1 to 4.\n";
        }

        if (choice != 4) {
            cout << "\nPress Enter to return to the menu...";
            cin.ignore(10000, '\n');
            cin.get();
        }

    } while (choice != 4);

    return 0;
}
