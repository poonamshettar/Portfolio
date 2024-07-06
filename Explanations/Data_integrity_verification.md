#### Merkle trees

For effeciently verifying large sets of data merkle tree also known as hash trees can be used.Merkle trees, highly valued for its capacity to detect changes in data makes it a fundamental component in technologies that demand strong data verification mechanisms.

[click for implementation](../codes/merkle_tree.cpp)

##### Complexity Analysis

| Operation       | Complexity |
| --------------- | ---------- |
| Space           | O(n)       |
| Searching       | O(logn)    |
| Traversal       | O(n)       |
| Insertion       | O(logn)    |
| Deletion        | O(logn)    |
| Synchronization | O(logn)    |

#### CRC(Cyclic Redundancy Check)

CRC is widely used for error detection on network devices for maitaining data integrity between the sender and the reciever.CRC is preferred in various applications such as in telecommunications, networking protocols and disk storage systems as it is simple and effecient to implement.

[click for implementation](../codes/CRC/crc.md)
