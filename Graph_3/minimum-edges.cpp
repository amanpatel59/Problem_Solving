int minimumEdgeReversal(vector<vector<int>> &edges, int n, int src, int dst)
{
    vector<vector<pair<int, int>>> adjList(n + 1);
    for (int i = 0; i < edges.size(); i++)
    {
        int u = edges[i][0], v = edges[i][1];
        adjList[u].push_back({v, 0});
        adjList[v].push_back({u, 1});
    }

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> q;
    q.push({0, src});
    vector<int> vis(n, 0);
    vis[src] = 1;
    while (!q.empty())
    {
        auto curr = q.top();
        int node = curr.second, toReverse = curr.first;
        vis[node] = 1;
        q.pop();
        if (node == dst)
            return toReverse;

        for (auto adj : adjList[node])
        {
            int cost = adj.second, adjNode = adj.first;
            if (!vis[adjNode])
                q.push({toReverse + cost, adjNode});
        }
    }

    return -1;
}