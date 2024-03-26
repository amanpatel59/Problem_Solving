/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void maxD(TreeNode* root , int curr_depth , int& ans)
    {
        if(root == NULL)
        {
            ans = max(ans,curr_depth);
            return;
        }

        maxD(root->left,curr_depth+1,ans);
        maxD(root->right,curr_depth+1,ans);
    }
    int maxDepth(TreeNode* root) {
        int ans = 0 ;
        maxD(root,0,ans);
        return ans;
    }
};