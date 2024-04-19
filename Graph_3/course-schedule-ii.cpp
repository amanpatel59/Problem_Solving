class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // KAHN's ALGORITHM

        vector<int>sequence;
        vector<int>indegree(numCourses,0);

        for(int i = 0 ; i < prerequisites.size() ; i++)
        {
            indegree[prerequisites[i][1]]++;
        }

        queue<int>q;
        for(int i = 0 ; i < indegree.size() ; i++)
        {
            if(indegree[i] == 0)q.push(i);
        }

        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            sequence.push_back(node);
            for(int i = 0 ; i < prerequisites.size() ; i++)
            {
                if(prerequisites[i][0] == node)
                {
                    indegree[prerequisites[i][1]]--;
                    if(indegree[prerequisites[i][1]] == 0)
                    {
                        q.push(prerequisites[i][1]);
                    }
                }
            }
        }
        reverse(sequence.begin(),sequence.end());

        if(sequence.size() == numCourses)return sequence;

        return {};
    }
};