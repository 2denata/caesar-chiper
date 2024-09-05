/*
Caesar Chiper
J. P. Denata
*/

#include <iostream>
#include <string>
using namespace std;

// Function to encrypt the text
string encrypt(string text, int shift) {
    string result = "";

    // Loop through each character in the text
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        // Encrypt uppercase letters (A-Z)
        if (isupper(ch)) {
            result += char(int(ch + shift - 65) % 26 + 65);
        }
        // Encrypt lowercase letters (a-z)
        else if (islower(ch)) {
            result += char(int(ch + shift - 97) % 26 + 97);
        }
        // If the character is not a letter, add it without encryption
        else {
            result += ch;
        }
    }
    return result;
}

// Function to decrypt the text
string decrypt(string text, int shift) {
    string result = "";

    // Loop through each character in the text
    for (int i = 0; i < text.length(); i++) {
        char ch = text[i];

        // Decrypt uppercase letters (A-Z)
        if (isupper(ch)) {
            result += char(int(ch - shift - 65 + 26) % 26 + 65);
        }
        // Decrypt lowercase letters (a-z)
        else if (islower(ch)) {
            result += char(int(ch - shift - 97 + 26) % 26 + 97);
        }
        // If the character is not a letter, add it without decryption
        else {
            result += ch;
        }
    }
    return result;
}

int main() {
    string text;
    int shift;
    
    // Input the text to be encrypted
    cout << "Enter the text: ";
    getline(cin, text);
    
    // Input the desired shift
    cout << "Enter the shift: ";
    cin >> shift;

    // Encrypt the text
    string encrypted = encrypt(text, shift);
    cout << "Encrypted text: " << encrypted << endl;

    // Decrypt the text back
    string decrypted = decrypt(encrypted, shift);
    cout << "Decrypted text: " << decrypted << endl;

    return 0;
}
