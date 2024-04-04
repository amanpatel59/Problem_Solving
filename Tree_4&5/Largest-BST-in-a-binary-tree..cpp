class Tree
{
public:
    bool bst;
    int size;
    int maxi;
    int mini;
};
Tree solve(Node *root, int &res)
{
    if (root == NULL)
    {
        return {true, 0, INT_MIN, INT_MAX};
    }

    Tree leftSubtree = solve(root->left, res);
    Tree rightSubtree = solve(root->right, res);

    Tree currNode;
    currNode.size = leftSubtree.size + rightSubtree.size + 1; 
    if (root->data > leftSubtree.maxi && root->data < rightSubtree.mini && leftSubtree.bst && rightSubtree.bst)
    {
        currNode.bst = true;
        res = max(res, currNode.size);
    }
    else
    {
        currNode.bst = false;
    }

    currNode.mini = min(root->data, leftSubtree.mini);
    currNode.maxi = max(root->data, rightSubtree.maxi);

    return currNode;
}
int largestBst(Node *root)
{
    int res = 0;
    Tree node = solve(root, res);
    return res;
}
