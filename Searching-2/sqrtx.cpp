class Solution {
public:
    bool check(int mid , int& x)
    {
        long long sq_mid = mid;
        sq_mid *= mid;
        return sq_mid <= x;
    }
    int mySqrt(int x) {
        int low = 1 , high = x , ans = 0;

        while(low <= high)
        {
            int mid = low + (high-low)/2;
            if((long long)mid*mid == x)return mid;

            bool flag = check(mid,x);
            if(flag)
            {
                low = mid+1;
            }
            else
            {
                high = mid-1;
            }
        }
        return high;
    }
};