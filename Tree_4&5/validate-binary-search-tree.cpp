// APPROACH 1

bool check(TreeNode *root, long long lower_limit, long long upper_limit)
{
    if (root == NULL)
        return true;

    if (root->val >= upper_limit or root->val <= lower_limit)
        return false;

    // BY GOING TO ONE SIDE WE ARE RESTRICTING THE POSSIBLE ELEMENTS FOR A NODE
    // LIKE agar ek element x ke left mei hai toh uski max possible value x-1 hai aur min -infinity
    return check(root->left, lower_limit, root->val) and check(root->right, root->val, upper_limit);
}
bool isValidBST(TreeNode *root)
{
    return check(root, LLONG_MIN, LLONG_MAX);
}

// APPROACH 2

int vL(TreeNode *root)
{
    if (root->left == NULL)
        return root->val;

    return min(root->val, vL(root->left));
}

int vR(TreeNode *root)
{
    if (root->right == NULL)
        return root->val;

    return max(root->val, vR(root->right));
}

bool validation(TreeNode *root, bool &flag)
{
    // base case
    if (!flag)
        return false;
    if (root == NULL)
        return true;

    long long left_max = LLONG_MIN;
    long long right_min = LLONG_MAX;
    if (root->left)
    {
        left_max = vR(root->left);
    }
    if (root->right)
    {
        right_min = vL(root->right);
    }

    flag = ((root->val > left_max) and (root->val < right_min) and validation(root->left, flag) and validation(root->right, flag));
    return flag;
}
bool isValidBST(TreeNode *root)
{
    bool flag = true;
    if (root == NULL)
        return true;
    if (root->left == NULL and root->right == NULL)
        return true;
    validation(root, flag);
    return flag;
}