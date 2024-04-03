#include <bits/stdc++.h>
using namespace std;

bool isPossible(vector<int> &prefix_a, vector<int> &prefix_b, int &book, int &n, int &m, int &maxTime)
{
    int maxBooksRead = -1;
    for (int i = 0; i <= n; i++)
    {
        int rem = maxTime - prefix_a[i];
        if (rem < 0)
            break;
        int ind = lower_bound(prefix_b.begin(), prefix_b.end(), rem) - prefix_b.begin();
        if (ind > m || prefix_b[ind] > rem)
        {
            ind--;
        }
        maxBooksRead = max(maxBooksRead, i + ind);
    }
    return maxBooksRead >= book ? true : false;
}

int main()
{
    int n, m, k;
    cin >> n;
    cin >> m;
    cin >> k;

    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for (int j = 0; j < m; j++)
    {
        cin >> b[j];
    }

    vector<int> prefix_a(n + 1, 0), prefix_b(m + 1, 0);
    prefix_a[1] = a[0];
    for (int i = 2; i <= n; i++)
    {
        prefix_a[i] += prefix_a[i - 1] + a[i - 1];
    }
    prefix_b[1] = b[0];
    for (int i = 2; i <= m; i++)
    {
        prefix_b[i] += prefix_b[i - 1] + b[i - 1];
    }

    int low = 0;
    int high = n + m;

    int ans = 0;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(prefix_a, prefix_b, mid, n, m, k))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }

    cout << ans << endl;

    return 0;
}