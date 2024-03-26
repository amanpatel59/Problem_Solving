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
    int findBottomLeftValue(TreeNode* root) {

        // COMPLEXITY BETTER KRNA HAI

        if(root == NULL)return 0;

        queue<TreeNode*>q;
        q.push(root);
        int ans = 0;
        while(!q.empty())
        {
            vector<int>level;
            int size = q.size();
            for(int i = 0 ; i < size ; i++)
            {
                auto p = q.front();
                q.pop();
                level.push_back(p->val);

                if(p->left)q.push(p->left);
                if(p->right)q.push(p->right);
            }
            ans = level[0];
        }

        return ans;
    }
};