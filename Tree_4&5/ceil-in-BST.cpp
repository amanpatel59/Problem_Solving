void preorder(Node *root, int &input, int &ans)
{
    if (root == NULL)
    {
        return;
    }

    if (root->data < input)
    {
        preorder(root->right, input, ans);
    }
    else
    {
        ans = root->data;
        preorder(root->left, input, ans);
    }
}

int findCeil(Node *root, int input)
{
    int ans = -1;
    preorder(root, input, ans);
    return ans;
}