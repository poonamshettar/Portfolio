## IP routing

<p align="center">
  <img src="../images/trie.png" alt="Merkle Tree Image" style="width: 400px;">
  <br>
  <em>Figure 1: IP Routing using trie [<a href="https://www.researchgate.net/figure/The-trie-lookup-structure-associated-with-the-routing-table-given-in-Table-7_fig3_220770958">5</a>]</em>
</p>
<br>
As IP address are stored in binary sequences Tries can be used for efficient storage and retrieval of these sequences where trie represents IP address.A Trie, also known as prefix tree which is a tree like data structure that can be used for efficient storage and retrieval of keys.It can be used in cyber security in IP routing for storing IP address for quick look-up.

### Time Complexity of Trie

![trie](../images/trie.png)

[code for trie](../codes/trie.md)

A further optimization could be possible using Radix trees.(Compressed Trie)
![radix tree](../images/radix_tree.png)
<br>

### Comaparision of performance of trie and radix tree

<figure>
  <img src="../images/trie_plot.png" alt="Trie Plot" style="width: 400px; float: left; margin-right: 20px;">
  <img src="../images/radix_tree_plot.png" alt="Radix Tree Plot" style="width: 400px; float: left;">
  <figcaption>Visualization of Trie and Radix Tree Plots <a href="https://blog.apnic.net/2021/06/04/storing-and-retrieving-ip-prefixes-efficiently/">[Reference]</a></figcaption>
</figure>
