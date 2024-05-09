// MEMO
// int check(int n, vector<int> &dp)
// {
//     // base case
//     if (n <= 2)
//     {
//         return n;
//     }
//     if (dp[n] != -1)
//     {
//         return dp[n];
//     }
//     return dp[n] = check(n - 1, dp) + check(n - 2, dp);
// }
// int climbStairs(int n)
// {
//     vector<int> dp(n + 1, -1);

//     return check(n, dp);
// }

// // TABULATION
// int climbStairs(int n)
// {
//     vector<int> dp(n + 1, -1);

//     dp[0] = dp[1] = 1;

//     for (int i = 2; i <= n; i++)
//     {
//         dp[i] = dp[i - 1] + dp[i - 2];
//     }

//     return dp[n];
// }

// SPACE OPTIMIZATION
int climbStairs(int n)
{
    int curr;
    int prev = 1;
    int prev2 = 1;

    if (n < 2)
    {
        return 1;
    }
    for (int i = 2; i <= n; i++)
    {
        curr = prev + prev2;
        prev2 = prev;
        prev = curr;
    }

    return prev;
}