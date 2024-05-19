
class Solution {
public:
    void allPaths(TreeNode* root , long long toAdd , int& targetSum , int& ans){
        if(root == NULL)return;
        long long currSum = root->val+toAdd;
        if(currSum == targetSum)ans++;
        allPaths(root->left,currSum,targetSum,ans);
        allPaths(root->right,currSum,targetSum,ans);
        return;
    }

    void traversal(TreeNode* root, int& targetSum , int& ans){
        if(root==NULL)return;

        allPaths(root,0,targetSum,ans);
        traversal(root->left,targetSum,ans);
        traversal(root->right,targetSum,ans);
    }
    int pathSum(TreeNode* root, int targetSum) {
        int ans = 0;
        traversal(root,targetSum,ans);
        return ans;
    }
};