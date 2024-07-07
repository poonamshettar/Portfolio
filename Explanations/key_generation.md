### Fermat's litlle theorem for key generation in RSA

- Fermat's Little Theorem is crucial for the RSA algorithm for secure encryption and decryption.

- The security of RSA relies on the difficulty of factoring large prime products. Fermat's theorem reinforces this by ensuring that operations with primes produce secure results, which is a key aspect of generating and validating keys.

- The theorem guarantees that, for a given prime \( p \) and an integer \( a \) not divisible by \( p \), \( a^{(p-1)} \equiv 1 \mod p \). This property is essential in creating reliable public keys that can encrypt data securely.

#### Steps:

1. Select two prime numbers \( p \) and \( q \).
2. Compute \( n = p \times q \) and \( \Phi(n) = (p-1) \times (q-1) \).
3. Choose \( e \) such that \( \text{gcd}(e, \Phi(n)) = 1 \).
4. Determine \( d \) such that \( (e \times d) \mod \Phi(n) = 1 \).

[click for code](../codes/fermat.md)
