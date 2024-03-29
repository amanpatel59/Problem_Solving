int solve(TreeNode *root, int &maxi)
{
    if (root == NULL)
    {
        return 0;
    }

    int longestLeftPath = solve(root->left, maxi);
    int longestRightPath = solve(root->right, maxi);

    maxi = max(maxi, longestLeftPath + longestRightPath);

    return max(longestLeftPath, longestRightPath) + 1;
}

int diameterOfBinaryTree(TreeNode *root)
{
    int maxi = 0;
    solve(root, maxi);
    return maxi;
}