int findCeil(Node *root, int input)
{
    if (root == NULL)
        return -1;


    Node *curr = root;
    int i = INT_MAX;
    while (curr)
    {
        if (curr->data == input)
            return input;
        if (curr->data > input)
        {
            i = min(i, curr->data);
            curr = curr->left;
        }
        else
            curr = curr->right;
    }

    return i == INT_MAX ? -1 : i;
}