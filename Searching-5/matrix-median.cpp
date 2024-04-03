
int findMedian(vector<vector<int>> &A)
{
    int row = A.size();
    int col = A[0].size();

    int totElements = row * col;

    int k = (totElements + 1) / 2;

    int low = 1e9;
    int high = -1e9;

    for (int i = 0; i < row; i++)
    {
        low = min(low, A[i][0]);
        high = max(high, A[i][col - 1]);
    }

    int res = -1;

    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        int count = 0;
        isPossible(A, count, row, mid);

        if (count < k)
        {
            low = mid + 1;
        }
        else
        {
            res = mid;
            high = mid - 1;
        }
    }
    return res;
}
