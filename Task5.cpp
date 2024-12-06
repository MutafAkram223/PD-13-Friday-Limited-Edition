#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

string charToMorse(char character);
string toMorseCode(string input);

int main() {
    string input;
    cout << "Enter a string for encryption: ";
    getline(cin, input);
    string encrypted = toMorseCode(input);
    cout << "Morse Code: " << encrypted << endl;

    fstream file;
    file.open("morse_code.txt", ios::app);
    file << input << endl;
    file << encrypted << endl;
    file.close();
}

string charToMorse(char character) {
    string morseMapping[26] = {
        ".-",    "-...",  "-.-.",  "-..",   ".",     "..-.",  "--.",   "....",  "..",    ".---",
        "-.-",   ".-..",  "--",    "-.",    "---",   ".--.",  "--.-",  ".-.",   "...",   "-",     
        "..-",   "...-",  ".--",   "-..-",  "-.--",  "--.."
    };
    character = toupper(character);
    if (character >= 'A' && character <= 'Z') {
        return morseMapping[character - 'A'];
    }
    else if (character == ' ') {
        return "-.-.-.-";
    }
    else {
        return "";
    }
}

string toMorseCode(string input) {
    string morseCode = "";
    for(int i = 0; i < input.length(); i++) {
        string morseChar = charToMorse(input[i]);
        if(morseChar != "") {
            morseCode = morseCode + morseChar + " ";
        }
    }
    return morseCode;
}