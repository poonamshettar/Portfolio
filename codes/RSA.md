## RSA Algorithm

RSA (Rivest-Shamir-Adleman) is an asymmetric encryption algorithm for secure data transmission. It uses a pair of keys: a public key for encryption and a private key for decryption. The security of RSA relies on the difficulty of factoring large prime numbers.

### Time and Space Complexity

| Operation      | Time Complexity | Space Complexity |
| -------------- | --------------- | ---------------- |
| Key Generation | O(log(n)^3)     | O(1)             |
| Encryption     | O(log(n)^3)     | O(1)             |
| Decryption     | O(log(n)^3)     | O(1)             |

Where:

- **n**: Size of the RSA modulus (product of two large prime numbers).

### Code

```cpp
#include <iostream>
#include <cmath>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

void generateRSAKeys(int p, int q, int& e, int& d, int& n) {
    n = p * q;
    int phi = (p - 1) * (q - 1);

    for (e = 2; e < phi; e++) {
        if (gcd(e, phi) == 1)
            break;
    }

    for (d = 2; d < phi; d++) {
        if ((d * e) % phi == 1)
            break;
    }
}

int encryptRSA(int msg, int e, int n) {
    return (int)pow(msg, e) % n;
}

int decryptRSA(int encryptedMsg, int d, int n) {
    return (int)pow(encryptedMsg, d) % n;
}

int main() {
    int p = 7, q = 11;
    int e, d, n;

    generateRSAKeys(p, q, e, d, n);

    int msg = 88;
    int encryptedMsg = encryptRSA(msg, e, n);
    int decryptedMsg = decryptRSA(encryptedMsg, d, n);

    cout << "Original message: " << msg << endl;
    cout << "Encrypted message: " << encryptedMsg << endl;
    cout << "Decrypted message: " << decryptedMsg << endl;

    return 0;
}
```
