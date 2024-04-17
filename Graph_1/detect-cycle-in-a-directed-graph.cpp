// USING KAHN'S ALGORITHM

void TopoSort(int node, vector<int> &vis, vector<int> adj[], stack<int> &st)
{
    if (vis[node])
        return;
    vis[node] = 1;

    for (auto adjNode : adj[node])
    {
        if (!vis[adjNode])
            TopoSort(adjNode, vis, adj, st);
    }
    st.push(node);
}
bool isCyclic(int V, vector<int> adj[])
{
    // code here
    stack<int> st;
    vector<int> vis(V, 0);
    TopoSort(0, vis, adj, st);
    if (st.size() < V)
        return 1;
    return 0;
}