### Priority Queue Using array

A type of queue that arranges elements based on their respective priority values.

#### Complexity Analysis

| Operation | Time Complexity |
| --------- | --------------- |
| enqueue() | O(1)            |
| dequeue() | O(n)            |
| peek()    | O(n)            |

#### Code

```cpp
#include <bits/stdc++.h>
using namespace std;

struct item {
	int value;
	int priority;
};

// Store the element of a priority queue
item pr[100000];

// Pointer to the last index
int size = -1;

void enqueue(int value, int priority)
{
	// Increase the size
	size++;

	// Insert the element
	pr[size].value = value;
	pr[size].priority = priority;
}

// Function to check the top element
int peek()
{
	int highestPriority = INT_MIN;
	int ind = -1;

	// Check for the element with
	// highest priority
	for (int i = 0; i <= size; i++) {

		// If priority is same choose
		// the element with the
		// highest value
		if (highestPriority == pr[i].priority && ind > -1
			&& pr[ind].value < pr[i].value) {
			highestPriority = pr[i].priority;
			ind = i;
		}
		else if (highestPriority < pr[i].priority) {
			highestPriority = pr[i].priority;
			ind = i;
		}
	}

	// Return position of the element
	return ind;
}


void dequeue()
{

	int ind = peek();

	for (int i = ind; i < size; i++) {
		pr[i] = pr[i + 1];
	}

	// Decrease the size of the
	// priority queue by one
	size--;
}

// Driver Code
int main()
{
	// Function Call to insert elements
	// as per the priority
	enqueue(10, 2);
	enqueue(14, 4);
	enqueue(16, 4);
	enqueue(12, 3);

	// Stores the top element
	// at the moment
	int ind = peek();

	cout << pr[ind].value << endl;

	// Dequeue the top element
	dequeue();

	// Check the top element
	ind = peek();
	cout << pr[ind].value << endl;

	// Dequeue the top element
	dequeue();

	// Check the top element
	ind = peek();
	cout << pr[ind].value << endl;

	return 0;
}
```
