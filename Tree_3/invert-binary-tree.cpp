TreeNode* invertTree(TreeNode* root) {
    // BASE CASE
    if(root==NULL) return NULL;

    TreeNode* leftSubtree = invertTree(root->left);
    TreeNode* rightSubtree = invertTree(root->right);

    root->left = rightSubtree;
    root->right = leftSubtree;

    return root;
}