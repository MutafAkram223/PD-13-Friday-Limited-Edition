#include <iostream>
#include <fstream>
#include <string>
using namespace std;

string getMissingLetters(string word);
void appendToFile(string word, string missing);

int main() {
    string word;
    cout << "Enter a word: ";
    getline(cin, word);
    string missing = getMissingLetters(word);
    appendToFile(word, missing);
    return 0;
}

string getMissingLetters(string word) {
    string missing = "";
    for(int i = 0; i < 26; i++) {
        char current = char(97 + i);
        bool found = false;
        for(int j = 0; j < word.length(); j++) {
            if(current == word[j]) {
                found = true;
                break;
            }
        }
        if(!found) {
            missing = missing + current;
        }
    }
    return missing;
}

void appendToFile(string word, string missing) {
    fstream file;
    file.open("alphabets.txt", ios::app);
    file << word << endl;
    file << missing << endl;
    file.close();
    if(missing.empty()) {
        cout << "All letters are present, so no need to append." << endl;
    }
    else {
        cout << "Missing letters: " << missing << endl;
    }
}