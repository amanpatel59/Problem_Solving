class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {

        vector<int> ans;

        int first = lower_bound(nums.begin(),nums.end(),target) - nums.begin();

        if(first == nums.size() or nums[first] != target)
        {
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        else
        {
            ans.push_back(first);
        }

        int last = upper_bound(nums.begin(),nums.end(),target) - nums.begin();
        ans.push_back(last-1);
        return ans;

    }
};