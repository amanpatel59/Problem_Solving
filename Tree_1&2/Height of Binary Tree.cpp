void maxD(TreeNode<int>* root , int curr_depth , int& ans)
    {
        if(root == NULL)
        {
            ans = max(ans,curr_depth);
            return;
        }

        maxD(root->left,curr_depth+1,ans);
        maxD(root->right,curr_depth+1,ans);
    }

int heightOfBinaryTree(TreeNode<int> *root)
{
	// Write your code here.
    int ans = 0 ;
        maxD(root,0,ans);
        return ans;

}
