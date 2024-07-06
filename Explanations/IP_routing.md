## IP routing

![trie](../images/trie_.png)
<br>
As IP address are stored in binary sequences Tries can be used for efficient storage and retrieval of these sequences where trie represents IP address.A Trie, also known as prefix tree which is a tree like data structure that can be used for efficient storage and retrieval of keys.It can be used in cyber security in IP routing for storing IP address for quick look-up.[code for trie](../codes/trie.cpp)

### Time Complexity of Trie

![trie](../images/trie.png)
<br>
| Operation | Time Complexity | Auxiliary Space |
|------------|------------------|-----------------|
| Insertion | O(n) | O(n\*m) |
| Searching | O(n) | O(1) |

A further optimization could be possible using Radix trees.(Compressed Trie)
![radix tree](../images/radix_tree.png)
<br>
Comaparision of performance

<p float="left">
  <img src="../images/trie_plot.png" width="500" />
  <img src="../images/radix_tree_plot.png" width="500" /> 
</p>
