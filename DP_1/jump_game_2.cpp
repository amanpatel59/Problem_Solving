// MEMO
// int check(vector<int> &nums, int index, int &n, vector<int> &dp)
// {
//     if (index >= n - 1)
//     {
//         return 0;
//     }
//     if (dp[index] != -1)
//         return dp[index];

//     int maxReachableIndex = nums[index] + index;
//     int minJumps = 1e9;
//     for (int ind = index + 1; ind <= min(maxReachableIndex, n); ind++)
//     {
//         minJumps = min(minJumps, 1 + check(nums, ind, n, dp));
//     }

//     return dp[index] = minJumps;
// }

// TABULATION
int jump(vector<int> &nums)
{
    int n = nums.size();
    vector<int> dp(n, 0);

    for (int index = n - 2; index >= 0; index--)
    {
        int maxReachableIndex = nums[index];
        int minJumps = 1e9;
        for (int ind = 1; ind <= maxReachableIndex; ind++)
        {
            if (ind + index < n)
                minJumps = min(minJumps, 1 + dp[index + ind]);
        }
        dp[index] = minJumps;
    }
    return dp[0];
}