// TABULATION
int doing2cases(vector<int> &nums)
{
    int adjacent = nums[0];
    int previousToAdjacent = nums[0];
    int curr = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        int pick = nums[i];
        if (i - 2 >= 0)
            pick = nums[i] + previousToAdjacent;
        int notPick = adjacent;
        curr = max(pick, notPick);
        previousToAdjacent = adjacent;
        adjacent = curr;
    }
    return curr;
}
int rob(vector<int> &nums)
{
    vector<int> temp = nums;
    temp.pop_back();
    int excludingLast = doing2cases(temp);

    for (int i = 1; i < nums.size(); i++)
        temp[i - 1] = nums[i];
    int excludingFirst = doing2cases(temp);

    return max(excludingLast, excludingFirst);
}