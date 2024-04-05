TreeNode *solve(ListNode *low, ListNode *high)
{
    if (low == high)
    {
        return NULL;
    }
    ListNode *slow = low;
    ListNode *fast = low;
    while (fast->next != high && fast->next->next != high)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    TreeNode *root = new TreeNode(slow->val);
    root->left = solve(low, slow);
    root->right = solve(slow->next, high);

    return root;
}
TreeNode *sortedListToBST(ListNode *head)
{
    ListNode *low = head;
    ListNode *high = NULL;
    return solve(low, high);
}