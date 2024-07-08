## Secure random number generation

### Entropy Pool

- Random numbers are crucial part for cryptographic algorithms.
- Data structures can be employed to manage and maintain a pool of entropy for generating secure random numbers.
- An entropy pool accumulates entropy from various sources, acting as a reservoir for randomness used in cryptographic operations.

#### Code

```py
import os
import hashlib
from cryptography.hazmat.primitives.kdf.pbkdf2 import PBKDF2HMAC
from cryptography.hazmat.primitives import hashes
from cryptography.hazmat.backends import default_backend

class EntropyPool:
    def __init__(self):
        self.pool = bytearray()

    def add_entropy(self, entropy_source):
        hashed_entropy = hashlib.sha256(entropy_source.encode()).digest()
        self.pool.extend(hashed_entropy)

    def get_bytes(self, n):
        if len(self.pool) < n:
            raise RuntimeError("Not enough entropy")

        random_bytes = self.pool[:n]
        self.pool = self.pool[n:]
        return random_bytes

entropy_pool = EntropyPool()
entropy_pool.add_entropy(str(os.urandom(32)))
entropy_pool.add_entropy(str(os.urandom(32)))

salt = os.urandom(16)
iterations = 100000
key_length = 32

kdf = PBKDF2HMAC(
    algorithm=hashes.SHA256(),
    length=key_length,
    salt=salt,
    iterations=iterations,
    backend=default_backend()
)

key = kdf.derive(entropy_pool.get_bytes(32))

print(f"Generated Key: {key.hex()}")
```
