### Fenwick Tree

To efficiently compute prefix sums and perform point updates in an array.

#### Complexity Analysis

| Aspect           | Complexity |
| ---------------- | ---------- |
| Construction     | O(N log N) |
| Point Update     | O(log N)   |
| Prefix Query     | O(log N)   |
| Range Query      | O(log N)   |
| Space Complexity | O(N)       |

#### Code

```cpp
#include <iostream>
#include <vector>
using namespace std;
void BIT(int ind, long long int x, vector<long long int> &b)
{
    for (int j = ind; j <= b.size(); j += j & (-j))
    {
        b[j] += x;
    }
}
long long int add_(int ind, vector<long long int> &b)
{
    long long int sum = 0;
    for (long long int j = ind; j > 0; j -= j & (-j))
    {
        sum += b[j];
    }
    return sum;
}
long long int range_sum(int l, int r, vector<long long int> &b)
{
    return add_(r, b) - add_(l - 1, b);
}
void range_update(int k, long long int u, vector<long long int> &b, vector<long long int> &a)
{
    BIT(k, u - a[k - 1], b);
    a[k - 1] = u;
}
int main()
{
    int n, q, p, l, r, k;
    long long int u;
    cin >> n >> q;
    vector<long long int> b(n + 1, 0);
    vector<long long int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        BIT(i + 1, a[i], b);
    }
    for (int i = 0; i < q; i++)
    {
        cin >> p;
        if (p == 2)
        {
            cin >> l >> r;
            cout << range_sum(l, r, b) << endl;
        }
        else
        {
            cin >> k >> u;
            range_update(k, u, b, a);
        }
    }

    return 0;
}
```
