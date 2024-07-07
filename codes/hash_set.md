### Hash Set

Also known as unordered set, stores unique elements but not in sorted order.

#### Complexity Analysis

| Aspect          | Complexity                                            |
| --------------- | ----------------------------------------------------- |
| Time Complexity | Best Case: O(1), Worst Case: O(n) (due to collisions) |
| Auxiliary Space | O(n)                                                  |

#### Code

```cpp
// C++ program to demonstrate the use of HashSet container

#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{
    // creating a HashSet of integer type
    unordered_set<int> ust;

    // Inserting values in random order and with duplicates
    // in a HashSet
    ust.insert(10);
    ust.insert(5);
    ust.insert(10);
    ust.insert(15);

    // printing the element in a set
    for (auto it : ust) {
        cout << it << ' ';
    }
    return 0;
}

```
