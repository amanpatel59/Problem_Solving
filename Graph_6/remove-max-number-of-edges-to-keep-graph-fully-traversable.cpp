class DisjointSet {
public:
    vector<int> size, parent;
    DisjointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++)
            parent[i] = i;
    }
    int findUpar(int u) {
        if (parent[u] == u)
            return u;
        return parent[u] = findUpar(parent[u]);
    }
    void unionBySize(int u, int v) {
        int ulp_u = findUpar(u), ulp_v = findUpar(v);
        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        } else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
    }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet dsA(n + 1), dsB(n + 1);
        int canRemove = 0;

        // FIRST TRAVELLING THE COMMON PATH i.e TYPE 3
        for (auto& edge : edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            if (type == 3) {
                if (dsA.findUpar(u) != dsA.findUpar(v) || dsB.findUpar(u) != dsB.findUpar(v)) {
                    dsA.unionBySize(u, v);
                    dsB.unionBySize(u, v);
                }
                else canRemove++;
            }
        }

        for (auto& edge : edges) {
            int type = edge[0], u = edge[1], v = edge[2];
            if (type == 1) {
                if (dsA.findUpar(u) == dsA.findUpar(v))
                    canRemove++;
                    dsA.unionBySize(u, v);
            } else if (type == 2) {
                if (dsB.findUpar(u) == dsB.findUpar(v))
                    canRemove++;
                    dsB.unionBySize(u, v);
            }

        }

        // Checking if both A and B can travel the whole graph or not
        int totalTraversedByA = dsA.size[dsA.findUpar(1)];
        int totalTraversedByB = dsB.size[dsB.findUpar(1)];

        if (totalTraversedByA < n || totalTraversedByB < n)
            return -1;

        return canRemove;
    }
};
