/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // BRUTE FORCE , TAKING UP TC: O(2N) AND SC: O(2N)
    // CAN'T WE JUST TRAVERSE AND COMPARE WHILE TRVERSING 
    // THIS WOULD SAVE THE SPACE OF STORING THE PATHS

    // bool path(TreeNode* root , TreeNode* p , vector<TreeNode*>& ans)
    // {
    //     if(root == NULL)return false;
    //     ans.push_back(root);

    //     if(root == p)
    //     {
    //         return true;
    //     }

    //     if(path(root->left,p,ans) or path(root->right,p,ans))return true;

    //     ans.pop_back();
    //     return false;
    // }


    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // BRUTE FORCE

        // vector<TreeNode*>path1;
        // vector<TreeNode*>path2;
        // path(root,p,path1);
        // path(root,q,path2);
        // TreeNode* ans;
        // for(int i = 0 ; i<path1.size() and i<path2.size() ; i++)
        // {
        //     if(path1[i] == path2[i])
        //     {
        //         ans = path1[i];
        //     }
        // }
        // return ans;


        // HERE WE AREN'T OCCUPYING ANY EXTRA SPACE

        if(root == NULL)return NULL;
        if(root == p or root == q)return root;

        TreeNode* left = lowestCommonAncestor(root->left,p,q);
        TreeNode* right = lowestCommonAncestor(root->right,p,q);

        if(left != NULL and right != NULL)return root;

        else if(right != NULL)return right;

        else
        return left;
    }
};