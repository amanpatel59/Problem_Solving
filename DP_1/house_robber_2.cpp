// TABULATION

int check(vector<int> &houses)
{
    int n = houses.size();

    int prev1 = houses[0];
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int pick = houses[i];

        if (i > 1)
            pick += prev2;

        int not_pick = 0 + prev1;

        int curr = max(pick, not_pick);

        prev2 = prev1;
        prev1 = curr;
    }
    return prev1;
}
int rob(vector<int> &nums)
{
    int n = nums.size();

    if (n == 1)
    {
        return nums[0];
    }
    vector<int> s_out, e_out;

    for (int i = 0; i < n; i++)
    {
        if (i != 0)
            s_out.push_back(nums[i]);

        if (i != n - 1)
            e_out.push_back(nums[i]);
    }

    return max(check(s_out), check(e_out));
}