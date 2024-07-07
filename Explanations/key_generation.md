## Key generation for Encryption and Decryption

### Fermat's litlle theorem for key generation in RSA

- Fermat's Little Theorem is crucial for the RSA algorithm for secure encryption and decryption.

- The security of RSA relies on the difficulty of factoring large prime products. Fermat's theorem reinforces this by ensuring that operations with primes produce secure results, which is a key aspect of generating and validating keys.

- The theorem guarantees that, for a given prime \( p \) and an integer \( a \) not divisible by \( p \), \( a^{(p-1)} \equiv 1 \mod p \). This property is essential in creating reliable public keys that can encrypt data securely.

#### Steps:

1. Select two prime numbers \( p \) and \( q \).
2. Compute $\( n = p \times q \) and \( \phi(n) = (p-1) \times (q-1) \)$.
3. Choose $\( e \) such that \( \text{gcd}(e, \phi(n)) = 1 \)$.
4. Determine $\( d \) such that \( (e \times d) \mod \phi(n) = 1 \)$.

[click for code](../codes/fermat.md)

---

### Catalan Numbers for key generation

- A random catalan number is chosen from the set of catalan numbers.
- The decimal form is converte to binary form and is verified for "bit-balance"(Equal number of 0's and 1's) property.
- A key using catalan numbers to be qualified as an encryption key must satisfy "bit-balance" property.[1](README.md#ref1)

[click for code](../codes/catalan.md)
