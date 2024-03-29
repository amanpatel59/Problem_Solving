// BFS

vector<int> printLeftView(BinaryTreeNode<int>* root) {
    // Write your code here.
    vector<int>ans;
    if(root == NULL)return ans;
    queue<BinaryTreeNode<int>*> q;
    q.push(root);

    while(!q.empty())
    {
        int size = q.size();
        for(int i = 0 ; i <size ; i++)
        {
            auto curr = q.front();
            q.pop();
            if(i==0)ans.push_back(curr->data);
            if(curr->left)q.push(curr->left);
            if(curr->right)q.push(curr->right);
        }
    }
    return ans;
}

