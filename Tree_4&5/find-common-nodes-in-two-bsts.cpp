void check(Node *root, set<int> &nodes)
{
    if (root == NULL)
    {
        return;
    }

    nodes.insert(root->data);
    check(root->left, nodes);
    check(root->right, nodes);
}

vector<int> findCommon(Node *root1, Node *root2)
{
    set<int> t1, t2;
    check(root1, t1);
    check(root2, t2);

    vector<int> res;
    for (auto it : t1)
    {
        if (t2.count(it))
        {
            res.push_back(it);
        }
    }

    return res;
}
