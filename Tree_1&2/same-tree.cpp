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
    // AGAR SAME HAI TOH INKA PRE/POST/IN ORDER TRAVERSALS BHI SAME HI HONGEY
    // TOH KISI BHI EK ORDER MEI TRAVERSE KRTE HUYE NODES CHECK KARATEY HUYE
    // CHECK KRTE HUYE CHALO

    bool isSameTree(TreeNode* p, TreeNode* q) {
        if(p==NULL or q==NULL)return (p==q);

        return (p->val==q->val and 
        isSameTree(p->left,q->left) and 
        isSameTree(p->right,q->right));
    }
};