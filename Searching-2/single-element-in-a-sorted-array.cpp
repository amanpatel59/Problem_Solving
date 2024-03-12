class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        // int ans = 0;
        // for(int i:nums)
        // {
        //     ans = ans ^ i;
        // }
        // return ans;

        // SINCE IT IS SORTED WE CAN TRY BINARY SEARCH
        if(nums.size()==1)
        {
            return nums[0];
        }
        int low = 1 , high = nums.size()-2;
        if(nums[0] != nums[1])
        {
            return nums[0];
        }
        else if(nums[nums.size()-1] != nums[nums.size()-2])
        {
            return nums[nums.size()-1];
        }

        while(low<=high)
        {
            int mid = (low+high)/2;

            if(nums[mid] != nums[mid+1] and nums[mid] != nums[mid-1])
            {
                return nums[mid];
            }

            if(mid % 2 == 0)
            {
                if(nums[mid] == nums[mid+1])
                {
                    low = mid+1;
                }
                else
                {
                    high = mid-1;
                }
            }
            else
            {
                if(nums[mid] == nums[mid+1])
                {
                    high = mid-1;
                }
                else
                {
                    low = mid+1;
                }
            }
        }
        return 0;
    }
};