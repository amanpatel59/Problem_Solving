// void trying_all_paths(TreeNode* &root , int target , vector<int>temp , vector<vector<int>>&ans)
// {
//     if(root == NULL)return;

//     if(root->left == NULL and root->right == NULL)
//     {
//         if(target-root->val == 0)
//         {
//             temp.push_back(root->val);
//             ans.push_back(temp);
//             temp.pop_back();
//         }
//         return;
//     }

//     target -= root->val;
//     temp.push_back(root->val);
//     trying_all_paths(root->left,target,temp,ans);
//     trying_all_paths(root->right,target,temp,ans);
// }
// vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
//     vector<vector<int>>ans;
//     vector<int>temp;

//     trying_all_paths(root,targetSum,temp,ans);

//     return ans;
// }

// COULD HAVE DONE THISSSSSS , CONCEPT IS SAME BUT BETTER WRITTEN

void solve(TreeNode *root, int targetSum, int sum, vector<int> temp, vector<vector<int>> &ans)
{
    if (root == NULL)
        return;
    sum += root->val;
    temp.push_back(root->val);
    if (root->left == NULL && root->right == NULL)
    {
        if (sum == targetSum)
        {
            ans.push_back(temp);
        }
        else
            return;
    }
    solve(root->left, targetSum, sum, temp, ans);
    solve(root->right, targetSum, sum, temp, ans);
}
vector<vector<int>> pathSum(TreeNode *root, int targetSum)
{
    int sum = 0;
    vector<vector<int>> ans;
    vector<int> temp;
    solve(root, targetSum, sum, temp, ans);
    return ans;
}