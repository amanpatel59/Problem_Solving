
int dfs(int node, vector<int> adjList[], int &ans)
{
    int maxi = 0;

    for (auto adjNode : adjList[node])
    {
        int dist = dfs(adjNode, adjList, ans);

        ans = max(ans, maxi + dist);

        maxi = max(maxi, dist);
    }

    return 1 + maxi;
}

int Solution::solve(vector<int> &A)
{
    int n = A.size();
    int root = -1;
    vector<int> adjList[n];

    for (int i = 0; i < n; i++)
    {
        if (A[i] != -1)
        {
            adjList[A[i]].push_back(i);
        }
        else
        {
            root = i;
        }
    }

    int ans = 0;

    dfs(root, adjList, ans);

    return ans;
}
