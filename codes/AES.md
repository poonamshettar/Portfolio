### AES Algorithm

AES (Advanced Encryption Standard) is a symmetric encryption algorithm used for securing sensitive data. It supports key lengths of 128, 192, or 256 bits and operates on fixed-size blocks of data.

#### Time and Space Complexity

| Operation     | Time Complexity | Space Complexity |
| ------------- | --------------- | ---------------- |
| Key Expansion | O(1)            | O(1)             |
| Encryption    | O(Nr \* Nb^2)   | O(1)             |

Where:

- **Nr**: Number of rounds.
- **Nb**: Number of columns.

#### Code

```cpp
#include <iostream>
#include <iomanip>
#include <cstring>
using namespace std;

const int Nb = 4;
const int Nk = 4;
const int Nr = 10;

unsigned char sbox[256] = {
};


unsigned char Rcon[11] = {
};

void subBytes(unsigned char state[][Nb]) {
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < Nb; j++) {
            state[i][j] = sbox[state[i][j]];
        }
    }
}

void shiftRows(unsigned char state[][Nb]) {
    unsigned char temp;

    temp = state[1][0];
    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp;

    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;
    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;

    temp = state[3][0];
    state[3][0] = state[3][3];
    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = temp;
}

void mixColumns(unsigned char state[][Nb]) {
    unsigned char tmp, tm, t;

    for (int i = 0; i < 4; i++) {
        t = state[0][i];
        tmp = state[0][i] ^ state[1][i] ^ state[2][i] ^ state[3][i];
        tm = state[0][i] ^ state[1][i];
        tm = xtime(tm);
        state[0][i] ^= tm ^ tmp;
        tm = state[1][i] ^ state[2][i];
        tm = xtime(tm);
        state[1][i] ^= tm ^ tmp;
        tm = state[2][i] ^ state[3][i];
        tm = xtime(tm);
        state[2][i] ^= tm ^ tmp;
        tm = state[3][i] ^ t;
        tm = xtime(tm);
        state[3][i] ^= tm ^ tmp;
    }
}

void aesEncrypt(unsigned char input[4 * Nb], unsigned char key[4 * Nk], unsigned char output[4 * Nb]) {
    unsigned char state[4][Nb];
    unsigned char roundKey[4 * Nb];

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < Nb; ++j) {
            state[i][j] = input[j * 4 + i];
        }
    }

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < Nk; ++j) {
            roundKey[i * 4 + j] = key[j * 4 + i];
        }
    }

    addRoundKey(state, roundKey);

    for (int round = 1; round < Nr; ++round) {
        subBytes(state);
        shiftRows(state);
        mixColumns(state);
        addRoundKey(state, roundKey + round * 4 * Nb);
    }

    subBytes(state);
    shiftRows(state);
    addRoundKey(state, roundKey + Nr * 4 * Nb);

    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < Nb; ++j) {
            output[j * 4 + i] = state[i][j];
        }
    }
}

int main() {
    unsigned char input[16] = {0x32, 0x55, 0x31, 0xe6, 0x43, 0x5a, 0x31, 0x37, 0xf6, 0x50, 0x98, 0x07, 0xa8, 0x8d, 0xa2, 0x34};
    unsigned char key[16] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    unsigned char output[16];

    aesEncrypt(input, key, output);

    cout << "AES Encrypted Output:" << endl;
    for (int i = 0; i < 16; ++i) {
        cout << hex << setfill('0') << setw(2) << (int)output[i] << " ";
    }
    cout << endl;

    return 0;
}
```
