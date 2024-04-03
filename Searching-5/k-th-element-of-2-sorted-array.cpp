
int kthElement(vector<int> &arr1, vector<int> &arr2, int n, int m, int k)
{
    if (n > m)
    {
        return kthElement(arr2, arr1, m, n, k);
    }

    int low = max(0, k - m);
    int high = min(n, k);

    while (low <= high)
    {
        int mid1 = low + (high - low) / 2;
        int mid2 = k - mid1;

        int left1 = (mid1 - 1 < 0) ? -1e9 : arr1[mid1 - 1];
        int right1 = (mid1 == n) ? 1e9 : arr1[mid1];
        int left2 = (mid2 - 1 < 0) ? -1e9 : arr2[mid2 - 1];
        int right2 = (mid2 == m) ? 1e9 : arr2[mid2];

        if (left1 <= right2 && left2 <= right1)
        {
            return max(left1, left2);
        }
        else if (left1 > right2)
        {
            high = mid1 - 1;
        }
        else if (left2 > right1)
        {
            low = mid1 + 1;
        }
    }

    return 0;
}