#include <iostream>
#include <vector>
#include <string>

using namespace std;

void generateKeyTable(string key, char keyTable[5][5]) {
    bool exists[26] = {false};
    exists['J' - 'A'] = true; // Treat 'J' as 'I'
    int row = 0, col = 0;
    
    for (char c : key) {
        if (c == 'J') c = 'I';
        if (!exists[c - 'A']) {
            keyTable[row][col] = c;
            exists[c - 'A'] = true;
            col++;
            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }
    
    for (char c = 'A'; c <= 'Z'; c++) {
        if (!exists[c - 'A']) {
            keyTable[row][col] = c;
            col++;
            if (col == 5) {
                col = 0;
                row++;
            }
        }
    }
}

void preprocessText(string &text) {
    for (char &c : text) {
        if (c == 'J') c = 'I';
    }
    string processedText = "";
    for (size_t i = 0; i < text.length(); i += 2) {
        processedText += text[i];
        if (i + 1 < text.length()) {
            if (text[i] == text[i + 1]) {
                processedText += 'X';
                i--;
            } else {
                processedText += text[i + 1];
            }
        } else {
            processedText += 'X';
        }
    }
    text = processedText;
}

void findPosition(char keyTable[5][5], char c, int &row, int &col) {
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 5; col++) {
            if (keyTable[row][col] == c) return;
        }
    }
}

string encrypt(string text, char keyTable[5][5]) {
    preprocessText(text);
    string ciphertext = "";
    for (size_t i = 0; i < text.length(); i += 2) {
        int row1, col1, row2, col2;
        findPosition(keyTable, text[i], row1, col1);
        findPosition(keyTable, text[i + 1], row2, col2);
        
        if (row1 == row2) {
            ciphertext += keyTable[row1][(col1 + 1) % 5];
            ciphertext += keyTable[row2][(col2 + 1) % 5];
        } else if (col1 == col2) {
            ciphertext += keyTable[(row1 + 1) % 5][col1];
            ciphertext += keyTable[(row2 + 1) % 5][col2];
        } else {
            ciphertext += keyTable[row1][col2];
            ciphertext += keyTable[row2][col1];
        }
    }
    return ciphertext;
}

string decrypt(string text, char keyTable[5][5]) {
    string plaintext = "";
    for (size_t i = 0; i < text.length(); i += 2) {
        int row1, col1, row2, col2;
        findPosition(keyTable, text[i], row1, col1);
        findPosition(keyTable, text[i + 1], row2, col2);
        
        if (row1 == row2) {
            plaintext += keyTable[row1][(col1 + 4) % 5];
            plaintext += keyTable[row2][(col2 + 4) % 5];
        } else if (col1 == col2) {
            plaintext += keyTable[(row1 + 4) % 5][col1];
            plaintext += keyTable[(row2 + 4) % 5][col2];
        } else {
            plaintext += keyTable[row1][col2];
            plaintext += keyTable[row2][col1];
        }
    }
    return plaintext;
}

int main() {
    string key, plaintext;
    char keyTable[5][5];

    cout << "Enter the key: ";
    cin >> key;

    cout << "Enter the plaintext: ";
    cin >> plaintext;

    generateKeyTable(key, keyTable);

    string encryptedText = encrypt(plaintext, keyTable);
    cout << "Encrypted text: " << encryptedText << endl;

    string decryptedText = decrypt(encryptedText, keyTable);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
