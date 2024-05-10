
// APPROACH 1

// void robbing(int& ans , int sum , vector<int>&nums , int index)
// {
//     if(index+2 >= nums.size())
//     {
//         ans = max(ans,sum);
//         return;
//     }
//     for(int i = index+2 ; i < nums.size() ; i++)
//     {
//         robbing(ans,sum+nums[i],nums,i);
//     }
//     return;
// }

// int rob(vector<int>& nums) {
//     if(nums.size()==1)return nums[0];
//     if(nums.size()==2)return max(nums[0],nums[1]);

//     int ans = 0 , sum = 0 , index = 0;
//     robbing(ans,nums[0],nums,0);
//     // robbing(ans,nums[1],nums,1);
//     return ans;
// }

// APPROACH 2

// int robbing(int index , vector<int>&nums)
// {
//     if (index >= nums.size()) {
//         return 0;
//     }

//     int robCurrent = nums[index] + robbing(index + 2, nums);
//     int skipCurrent = robbing(index + 1, nums);

//     return max(robCurrent,skipCurrent);
// }
// int rob(vector<int>& nums)
// {
//     if(nums.size() == 1)return nums[0];
//     if(nums.size() == 2)return max(nums[0],nums[1]);

//     return robbing(0,nums);
// }

// APPROACH 3 , ADDING MEMO IN APPROACH 2

int robbingMemo(int index, vector<int> &nums, unordered_map<int, int> &memo)
{
    if (index >= nums.size())
    {
        return 0;
    }

    // Check if the result for the current index is already memoized
    if (memo.find(index) != memo.end())
    {
        return memo[index];
    }

    // Rob the current house, skip the next, and move to the house after that
    int robCurrent = nums[index] + robbingMemo(index + 2, nums, memo);

    // Skip the current house and move to the next
    int skipCurrent = robbingMemo(index + 1, nums, memo);

    // Update memoization table with the maximum of robbing or skipping the current house
    memo[index] = max(robCurrent, skipCurrent);

    return memo[index];
}

int rob(vector<int> &nums)
{
    if (nums.size() == 1)
        return nums[0];
    if (nums.size() == 2)
        return max(nums[0], nums[1]);

    int ans = 0;
    unordered_map<int, int> memo;
    ans = robbingMemo(0, nums, memo);

    return ans;
}