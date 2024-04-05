TreeNode *bstFromPreorder(vector<int> &preorder)
{
    int n = preorder.size();
    TreeNode *root = new TreeNode(preorder[0]);
    stack<TreeNode *> st;
    st.push(root);

    for (int i = 1; i < n; i++)
    {
        TreeNode *node = new TreeNode(preorder[i]);
        if (st.top()->val > node->val)
        {
            st.top()->left = node;
            st.push(node);
        }
        else
        {
            TreeNode *prev = NULL;
            while (!st.empty() && st.top()->val < node->val)
            {
                prev = st.top();
                st.pop();
            }
            prev->right = node;
            st.push(node);
        }
    }
    return root;
}
