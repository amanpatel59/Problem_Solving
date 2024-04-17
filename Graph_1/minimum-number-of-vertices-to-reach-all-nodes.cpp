class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        // ANYONE WITH INDEGREE == "0" , CANNOT BE REACHED UNTILL IT IS THE STARTING POINT ITSELF
        // THEREFORE WE NEED ALL THE VERTICES WITH INDEGREE == "0"
        // AND THAT'S ALL , SINCE ANY VERTEX WITH INDEGREE > 0 IS REACHABLE FROM SOME OTHER VERTEX
        vector<int>indegree(n,0);

        for(int i = 0 ; i < edges.size() ; i++){
            indegree[edges[i][1]]++;
        }

        vector<int>ans;
        for(int i = 0 ; i < n ; i++)if(indegree[i]==0)ans.push_back(i);
        return ans;
    }
};