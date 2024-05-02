class DisjointSet{
public:
    vector<int>rank,size,parent;
    DisjointSet(int n){
        rank.resize(n,0);
        size.resize(n,1);
        parent.resize(n);
        for(int i = 0 ; i < n ; i++)parent[i] = i;
    }
    int findUPar(int u){
        if(parent[u] == u)return u;
        return parent[u] = findUPar(parent[u]);
    }
    void unionByRank(int u , int v){
        int ulp_u = findUPar(u) , ulp_v = findUPar(v);
        if(ulp_u == ulp_v)return;
        if(rank[ulp_u] < rank[ulp_v])parent[ulp_u] = ulp_v;
        else if(rank[ulp_v] < rank[ulp_u])parent[ulp_v] = ulp_u;
        else{
            parent[ulp_u] = ulp_v;
            rank[ulp_v]+=1;
        }
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        int maxNode = 0;
        for (auto& edge : edges) {
            maxNode = max(maxNode, max(edge[0], edge[1]));
        }

        DisjointSet ds(maxNode+1);
        vector<int>ans;
        for(auto it : edges){
            int u = it[0] , v = it[1];
            if(ds.findUPar(u) == ds.findUPar(v)){
                ans = {u,v};
            }
            else{
                ds.unionByRank(u,v);
            }
        }
        return ans;
    }
};