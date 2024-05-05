class Solution {
public:
    // SIMPLE RECURSIVE SOLUTION
    // WILL RESULT IN TLE , SINCE TC : O(2^n) and n here goes till 2500
    // void allLIS(vector<int>&nums , int index , int elementsTaken , int& ans ,
    // int lastTaken){
    //     if(index >= nums.size()){
    //         ans = max(ans,elementsTaken);
    //         return;
    //     }

    //     // not pick
    //     allLIS(nums,index+1,elementsTaken,ans,lastTaken);

    //     //pick
    //     if(nums[index] >
    //     lastTaken)allLIS(nums,index+1,elementsTaken+1,ans,nums[index]);
    // }
    // int lengthOfLIS(vector<int>& nums) {
    //     int ans = 1;
    //     allLIS(nums,0,0,ans,INT_MIN);
    //     return ans;
    // }

    // TO REDUCE THE TLE AND RESTRICT THE REDUNDANT COMPUTATIONS
    // MEMOIZATION

    // void allLIS(vector<int>& nums, int index, int elementsTaken, int& ans,
    //             int lastTaken, unordered_map<int, int>& mp) {
    //     if (index >= nums.size()) {
    //         ans = max(ans, elementsTaken);
    //         return;
    //     }

    //     if (mp.find(index) != mp.end()) {
    //         ans = max(ans, elementsTaken + mp[index]);
    //         mp[index] = ans;
    //         return;
    //     }

    //     // Not pick
    //     allLIS(nums, index + 1, elementsTaken, ans, lastTaken, mp);

    //     // Pick
    //     if (nums[index] > lastTaken)
    //         allLIS(nums, index + 1, elementsTaken + 1, ans, nums[index], mp);

    //     mp[index] = elementsTaken+mp[index];
    // }

    // int lengthOfLIS(vector<int>& nums) {
    //     int ans = 1;
    //     unordered_map<int, int> mp;
    //     allLIS(nums, 0, 0, ans, INT_MIN, mp);
    //     return ans;
    // }

    // MEMOIZATION SOLUTION IS WRONG NEED TO CORRECT IT AND SEE WHAT ARE THE LOGICAL ERROR!!!


    
    // TABULATION

    int lengthOfLIS(vector<int>& nums) {
        vector<int>dp(nums.size());
        dp[0] = 1;

        for(int i = 1 ; i < nums.size() ; i++){
            int maxi = 1;
            for(int j = 0 ; j < i ; j++){
                if(nums[j] < nums[i])maxi = max(dp[j]+1,maxi);
            }
            dp[i] = maxi;
        }
        int ans = 1;
        for(auto i : dp)ans = max(ans,i);
        return ans;
    }
};