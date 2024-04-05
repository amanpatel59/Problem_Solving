void inorder(Node *root, Node *&prev)
{
    if (root == NULL)
    {
        return;
    }

    inorder(root->left, prev);

    
    if (prev != NULL)
    {
        prev->right = root;
        root->left = prev;
    }
    prev = root;
    inorder(root->right, prev);
}

void leftRecur(Node *root, Node *&head)
{
    if (root == NULL)
    {
        return;
    }

    head = root;

    leftRecur(root->left, head);
}

void rightRecur(Node *root, Node *&tail)
{
    if (root == NULL)
    {
        return;
    }

    tail = root;

    rightRecur(root->right, tail);
}
Node *bTreeToCList(Node *root)
{
    Node *head = NULL;
    Node *tail = NULL;
    Node *prev = NULL;
    
    leftRecur(root, head);
    rightRecur(root, tail);

    inorder(root, prev);

    head->left = tail;
    tail->right = head;

    return head;
}