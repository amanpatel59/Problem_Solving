bool solve(int *preorder, int &size)
{
    int leftmini = -1e9;
    int leftmaxi = preorder[0] - 1;
    int rightmini = preorder[0] + 1;
    int rightmaxi = 1e9;

    for (int node = 1; node < size - 1; node++)
    {
        int left = preorder[node];
        int right = preorder[node + 1];

        if (left >= leftmini && left <= leftmaxi)
        {
            if (right >= rightmini && right <= rightmaxi)
            {
                return false;
            }
            leftmaxi = left - 1;
            rightmini = left + 1;
        }
        else if (right >= rightmini && right <= rightmaxi)
        {
            rightmini = right + 1;
            leftmaxi = right - 1;
        }
    }
    return true;
}
