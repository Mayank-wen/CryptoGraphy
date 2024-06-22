#include <iostream>
#include <string>
#include <vector>

using namespace std;

string encrypt(const string &plaintext, int numCols) {
    int numRows = (plaintext.length() + numCols - 1) / numCols;
    vector<string> grid(numRows, string(numCols, ' '));

    for (size_t i = 0; i < plaintext.length(); ++i) {
        grid[i / numCols][i % numCols] = plaintext[i];
    }

    string ciphertext;
    for (int col = 0; col < numCols; ++col) {
        for (int row = 0; row < numRows; ++row) {
            if (grid[row][col] != ' ') {
                ciphertext += grid[row][col];
            }
        }
    }

    return ciphertext;
}

string decrypt(const string &ciphertext, int numCols) {
    int numRows = (ciphertext.length() + numCols - 1) / numCols;
    int numFullCols = ciphertext.length() % numCols;
    vector<string> grid(numRows, string(numCols, ' '));

    size_t index = 0;
    for (int col = 0; col < numCols; ++col) {
        for (int row = 0; row < numRows; ++row) {
            if (col >= numFullCols && row == numRows - 1) continue;
            if (index < ciphertext.length()) {
                grid[row][col] = ciphertext[index++];
            }
        }
    }

    string plaintext;
    for (int row = 0; row < numRows; ++row) {
        for (int col = 0; col < numCols; ++col) {
            if (grid[row][col] != ' ') {
                plaintext += grid[row][col];
            }
        }
    }

    return plaintext;
}

int main() {
    string plaintext;
    int numCols;

    cout << "Enter the plaintext: ";
    getline(cin, plaintext);

    cout << "Enter the number of columns: ";
    cin >> numCols;

    string encryptedText = encrypt(plaintext, numCols);
    cout << "Encrypted text: " << encryptedText << endl;

    string decryptedText = decrypt(encryptedText, numCols);
    cout << "Decrypted text: " << decryptedText << endl;

    return 0;
}
