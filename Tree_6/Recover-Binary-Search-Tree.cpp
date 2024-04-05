void inorder(TreeNode *root, TreeNode *&first, TreeNode *&second, TreeNode *&prev)
{
    if (root == NULL)
    {
        return;
    }
    inorder(root->left, first, second, prev);
    if (prev != NULL && root->val < prev->val)
    {
        if (first == NULL)
        {
            first = prev;
        }
        second = root;
    }
    prev = root;
    inorder(root->right, first, second, prev);
}

void recoverTree(TreeNode *root)
{
    TreeNode *first = NULL;
    TreeNode *second = NULL;
    TreeNode *prev = NULL;

    inorder(root, first, second, prev);

    swap(first->val, second->val);
}
