class Solution {
public:
    // simple recursion
    // int countWays(int& n , int curr = 0){
    //     if(curr == n)return 1;
    //     if(curr > n)return 0;

    //     // go 1
    //     int way1 = countWays(n,curr+1);
    //     // go 2
    //     int way2 = countWays(n,curr+2);

    //     return way1+way2;
    // }
    // int climbStairs(int n) {
    //     return countWays(n);
    // }

    // MEMOIZATION (using map)

    // int countWays(int& n , unordered_map<int,int>&mp, int curr = 0){
    //     if(curr == n)return 1;
    //     if(curr > n)return 0;

    //     if(mp.find(curr) != mp.end())return mp[curr];
    //     // go 1
    //     int way1 = countWays(n,mp,curr+1);
    //     // go 2
    //     int way2 = countWays(n,mp,curr+2);

    //     return mp[curr] = way1+way2;
    // }
    // int climbStairs(int n) {
    //     unordered_map<int,int>mp;
    //     return countWays(n,mp);
    // }

    // MEMOIZATION (using vector) -> top-down

    // int countWays(int& n , vector<int>&dp, int curr = 0){
    //     if(curr == n)return 1;
    //     if(curr > n)return 0;

    //     if(dp[curr] != -1)return dp[curr];
    //     // go 1
    //     int way1 = countWays(n,dp,curr+1);
    //     // go 2
    //     int way2 = countWays(n,dp,curr+2);

    //     return dp[curr] = way1+way2;
    // }
    // int climbStairs(int n) {
    //     vector<int>dp(n+1,-1);
    //     countWays(n,dp);
    //     return dp[0];
    // }

    // TABULATION -> bottom up , going from top

    // int climbStairs(int n) {
    //     if(n <= 2)return n;
    //     vector<int>dp(n+1,0);
    //     dp[n] = 1;
    //     dp[n-1] = 1;
    //     for(int i = n-2 ; i >= 0 ; i--)dp[i] = dp[i+1]+dp[i+2];
    //     return dp[0];
    // }

    // TABULATION -> bottom up , going from bottom

    // int climbStairs(int n) {
    //     if(n <= 2)return n;
    //     vector<int>dp(n+1,0);
    //     dp[0] = 1;
    //     dp[1] = 1;
    //     for(int i = 2 ; i <= n ; i++)dp[i] = dp[i-1]+dp[i-2];
    //     return dp[n];
    // }

    // SPACE OPTIMIZATION

    int climbStairs(int n) {
        if (n <= 2)
            return n;
        int firstStep = 1;
        int secondStep = 1;
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            ans = firstStep + secondStep;
            secondStep = firstStep;
            firstStep = ans;
        }
        return ans;
    }
};