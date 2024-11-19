#include <iostream>
#include <string>

using namespace std;

class CaesarCipher {
private:
    int shift;

public:
    CaesarCipher(int shiftValue) : shift(shiftValue) {}

    string encrypt(const string& input) {
        string result = input;
        for (size_t i = 0; i < result.length(); ++i) {
            if (isalpha(result[i])) {
                char base = islower(result[i]) ? 'a' : 'A';
                result[i] = (result[i] - base + shift) % 26 + base;
            }
        }
        return result;
    }

    string decrypt(const string& input) {
        string result = input;
        for (size_t i = 0; i < result.length(); ++i) {
            if (isalpha(result[i])) {
                char base = islower(result[i]) ? 'a' : 'A';
                result[i] = (result[i] - base - shift + 26) % 26 + base;
            }
        }
        return result;
    }

    void setShift(int newShift) {
        shift = newShift;
    }

    int getShift() const {
        return shift;
    }
};

int main() {
    int shift;
    char action;
    string text;

    cout << "amount of text shift: ";
    cin >> shift;

    CaesarCipher cipher(shift);

    cout << "encrypt or decrypt? (e/d): ";
    cin >> action;

    cout << "enter text: ";
    cin.ignore();
    getline(cin, text);

    if (action == 'e' || action == 'E') {
        string encrypted = cipher.encrypt(text);
        cout << "ciphertext: " << encrypted << endl;
    }
    else if (action == 'd' || action == 'D') {
        string decrypted = cipher.decrypt(text);
        cout << "decrypted text: " << decrypted << endl;
    }
    else {
        cout << "error!" << endl;
    }

    return 0;
}
