### Hash Set

Also known as unordered set, stores unique elements but not in sorted order.

#### Complexity Analysis

| Aspect          | Complexity                                            |
| --------------- | ----------------------------------------------------- |
| Time Complexity | Best Case: O(1), Worst Case: O(n) (due to collisions) |
| Auxiliary Space | O(n)                                                  |

#### Code

```cpp

#include <iostream>
#include <unordered_set>
using namespace std;

int main()
{

    unordered_set<int> ust;

    ust.insert(10);
    ust.insert(5);
    ust.insert(10);
    ust.insert(15);

    for (auto it : ust) {
        cout << it << ' ';
    }
    return 0;
}

```
