### Run Length Encoding

Replaces consecutive identical data elements with a count and a single value.

#### Complexity Analysis

| Operation | Time Complexity | Auxiliary Space |
| --------- | --------------- | --------------- |
| Insertion | O(n)            | O(1)            |
| Searching | O(n)            | O(1)            |

#### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void printRLE(string str)
{
	int n = str.length();
	for (int i = 0; i < n; i++) {


		int count = 1;
		while (i < n - 1 && str[i] == str[i + 1]) {
			count++;
			i++;
		}

		cout << str[i] << count;
	}
}

int main()
{
	string str = "wwwwaaadexxxxxxywww";
	printRLE(str);
	return 0;
}
```
