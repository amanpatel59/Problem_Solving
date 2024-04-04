
class Tree
{
public:
    int sum;
    int maxi;
    int mini;
    bool isBst;
};

Tree solve(TreeNode *root, int &maxSum)
{
    if (root == NULL)
    {
        return {0, INT_MIN, INT_MAX, true};
    }

    Tree leftSubTree = solve(root->left, maxSum);
    Tree rightSubTree = solve(root->right, maxSum);

    Tree currNode;
    currNode.sum = leftSubTree.sum + rightSubTree.sum + root->val;
    if (leftSubTree.isBst && rightSubTree.isBst && root->val > leftSubTree.maxi && root->val < rightSubTree.mini)
    {
        currNode.isBst = true;
        maxSum = max(maxSum, currNode.sum);
    }
    else
    {
        currNode.isBst = false;
    }

    currNode.mini = min(root->val, leftSubTree.mini);
    currNode.maxi = max(root->val, rightSubTree.maxi);

    return currNode;
}

int maxSumBST(TreeNode *root)
{
    int maxSum = 0;
    Tree node = solve(root, maxSum);
    return maxSum;
}