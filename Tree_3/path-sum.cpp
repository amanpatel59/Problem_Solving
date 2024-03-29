bool checking_all_paths(TreeNode *&root, int targetSum, int curr)
{
    if (root == NULL)
        return false;

    if (root->left == NULL and root->right == NULL)
    {
        curr += root->val;
        if (curr == targetSum)
            return true;
        return false;
    }

    return checking_all_paths(root->left, targetSum, curr + root->val) or checking_all_paths(root->right, targetSum, curr + root->val);
}

bool hasPathSum(TreeNode *root, int targetSum)
{
    return checking_all_paths(root, targetSum, 0);
}