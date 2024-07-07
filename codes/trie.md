### Trie

Trie, also known as prefix tree is a tree based structure that helps in fast search insertion and deletion operations.

#### Complexity Analysis

| Operation | Time Complexity | Auxiliary Space |
| --------- | --------------- | --------------- |
| Insertion | O(n)            | O(n\*m)         |
| Searching | O(n)            | O(1)            |

```cpp
#include <iostream>
#include <unordered_map>
using namespace std;

class node
{
public:
    unordered_map<char, node *> children;
    bool is_end_of_word;

    node()
    {
        is_end_of_word = false;
    }
};

class Trie
{
private:
    node *root;

public:
    Trie()
    {
        root = new node();
    }

    void insert(string word)
    {
        node *current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
            {
                current->children[c] = new node();
            }
            current = current->children[c];
        }
        current->is_end_of_word = true;
    }

    bool search(string word)
    {
        node *current = root;
        for (char c : word)
        {
            if (current->children.find(c) == current->children.end())
            {
                return false;
            }
            current = current->children[c];
        }
        return current != nullptr && current->is_end_of_word;
    }
};

int main()
{
    Trie trie;
    trie.insert("poonam");
    trie.insert("shettar");

    cout << (trie.search("poonam") ? "Found " : "Not found") << endl;

    return 0;
}
```
