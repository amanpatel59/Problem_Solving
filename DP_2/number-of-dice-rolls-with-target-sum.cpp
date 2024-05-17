class Solution {
public:
    int mod = 1e9 + 7;

    // SIMPLE RECURSIVE

    // int allWays(int n , int k , int target){
    //     if(n < 0 or target < 0)return 0;
    //     if(n == 0 and target == 0)return 1;

    //     int currAllWays = 0;
    //     for(int i = 1 ; i <= k ; i++){
    //         if(i <= target)currAllWays += allWays(n-1,k,target-i)%mod;
    //     }
    //     return currAllWays;
    // }
    // int numRollsToTarget(int n, int k, int target) {
    //     return allWays(n,k,target)%mod;
    // }

    // WITH MEMO
    // int allWays(int n , int k , int target , vector<vector<int>>&dp){
    //     if(n < 0 or target < 0)return 0;
    //     if(n == 0 and target == 0)return dp[n][target] = 1;

    //     if(dp[n][target] != -1)return dp[n][target];

    //     long long currAllWays = 0;
    //     for(int i = 1 ; i <= k ; i++){
    //         if(i <= target)currAllWays =
    //         (currAllWays+allWays(n-1,k,target-i,dp))%mod;
    //     }
    //     return dp[n][target] = currAllWays;
    // }
    // int numRollsToTarget(int n, int k, int target) {
    //     vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
    //     return allWays(n,k,target,dp)%mod;
    // }

    // TABULATION
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<long long>> dp(n + 1, vector<long long>(target + 1, 0));
        dp[0][0] = 1;
        // dp[i][j] -> number of ways to achieve j in i rolls
        // hence will need to calculate number of ways to achieve "0->target" in each roll
        for (int i = 1; i <= n; i++) {
            for (int t = 0; t <= target; t++) {
                for (int j = 1; j <= k; j++) {
                    if (t < j)continue;
                    dp[i][t] = (dp[i][t] + dp[i - 1][t - j]) % mod;
                }
            }
        }
        return dp[n][target];
    }
};