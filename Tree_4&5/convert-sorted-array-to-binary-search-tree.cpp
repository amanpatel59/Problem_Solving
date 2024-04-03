TreeNode *balancedStuff(int start, int end, vector<int> &nums)
{
    if (start > end)
        return NULL;

    int mid = start + (end - start) / 2;

    TreeNode *root = new TreeNode(nums[mid]);
    root->left = balancedStuff(start, mid - 1, nums);
    root->right = balancedStuff(mid + 1, end, nums);
    return root;
}
TreeNode *sortedArrayToBST(vector<int> &nums)
{
    return balancedStuff(0, nums.size() - 1, nums);
}