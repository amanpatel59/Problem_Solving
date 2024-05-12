class Solution {
public:
    // PURE RECURSION
    // WILL RESULT IN TLE

    // int bestPoss(vector<int>&nums , int indx){
    //     if(indx == 0)return nums[0];
    //     if(indx < 0)return 0;
    //     int pick = nums[indx]+bestPoss(nums,indx-2);
    //     int notPick = bestPoss(nums,indx-1);
    //     return max(pick , notPick);
    // }
    // int rob(vector<int>& nums) {
    //     return bestPoss(nums,nums.size()-1);
    // }


    // MEMOIZATION

    // int bestPoss(vector<int>&nums , int indx , vector<int>&dp){
    //     if(indx == 0)return dp[0] = nums[0];
    //     if(indx < 0)return 0;
    //     if(dp[indx] != -1)return dp[indx];
    //     int pick = nums[indx]+bestPoss(nums,indx-2,dp);
    //     int notPick = bestPoss(nums,indx-1,dp);
    //     return dp[indx] = max(pick , notPick);
    // }
    // int rob(vector<int>& nums) {
    //     vector<int>dp(nums.size(),-1);
    //     return bestPoss(nums,nums.size()-1,dp);
    // }


    // TABULATION
    // int rob(vector<int>& nums) {
    //     vector<long long>dp(nums.size(),0);
    //     dp[0] = nums[0];
    //     for(int i = 1 ; i < nums.size() ; i++){
    //         int pick = nums[i];
    //         if(i-2 >= 0)pick = nums[i] + dp[i-2];
    //         int notPick = dp[i-1];
    //         dp[i] = max(pick,notPick);
    //     }
    //     return dp[nums.size()-1];
    // }


    // SPACE OPTIMIZATION
    // SINCE WE ONLY REQUIRE INFO ABOUT PAST 2 WE CAN HAVE VARS INSTEAD OF A FULL VECTOR
    int rob(vector<int>& nums) {
        int adjacent = nums[0];
        int previousToAdjacent = nums[0];
        int curr = nums[0];
        for(int i = 1 ; i < nums.size() ; i++){
            int pick = nums[i];
            if(i-2 >= 0)pick = nums[i] + previousToAdjacent;
            int notPick = adjacent;
            curr = max(pick,notPick);
            previousToAdjacent = adjacent;
            adjacent = curr;
        }
        return curr;
    }
};