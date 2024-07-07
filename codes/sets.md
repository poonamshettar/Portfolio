### Set

Stores unique element in sorted oreder(increasing order).

#### Complexity Analysis

| Aspect          | Complexity |
| --------------- | ---------- |
| Time Complexity | O(log n)   |
| Auxiliary Space | O(n)       |

n- number of elements in the set.

#### Code

```cpp
#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<int> st;

    st.insert(10);
    st.insert(5);
    st.insert(10);
    st.insert(15);

    // printing the element in a set
    for (auto it : st) {
        cout << it << ' ';
    }
    return 0;
}
```
