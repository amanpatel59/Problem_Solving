bool isPossible(vector<int> &nums, int maxOperations, int mid)
{
    int count = 0;
    if (mid == 0)
        return false;
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] % mid == 0)
        {
            count += nums[i] / mid - 1;
        }
        else
        {
            count += nums[i] / mid;
        }
    }

    return count <= maxOperations;
}
int minimumSize(vector<int> &nums, int maxOperations)
{
    int low = 0;
    int high = *max_element(nums.begin(), nums.end());

    int res;
    while (low <= high)
    {
        int mid = low + (high - low) / 2;

        if (isPossible(nums, maxOperations, mid))
        {
            res = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    return res;
}