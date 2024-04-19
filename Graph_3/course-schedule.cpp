class Solution {
public:
    // DIRECT CYCLE DETECTION IMPLEMENTATION

    // bool dfsCycleCheck(int course, vector<vector<int>>& prerequisites, vector<int>&vis , vector<int>&curr_path)
    // {
    //     vis[course] = 1;
    //     curr_path[course] = 1;

    //     for(auto i : prerequisites)
    //     {
    //         if(i[1] == course)
    //         {
    //             if(!vis[i[0]] and dfsCycleCheck(i[0],prerequisites,vis,curr_path))return true;

    //             else if(curr_path[i[0]])return true;
    //         }
    //     }

    //     curr_path[course] = 0;
    //     return false;
    // }
    // bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
    //     vector<int>vis(numCourses,0);
    //     vector<int>curr_path(numCourses,0);
    //     for(int i = 0 ; i < numCourses ; i++)
    //     {
    //         if(!vis[i])
    //             if(dfsCycleCheck(i,prerequisites,vis,curr_path))return false;
    //     }
    //     return true;
    // }


    // USING KAHN's ALGO TO CHECK TOPO SORT
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites)
    {
        vector<int>indegree(numCourses,0);
        vector<int>vis(numCourses,0);

        for(int i = 0 ; i < prerequisites.size() ; i++)
        {
            indegree[prerequisites[i][1]]++;
        }

        queue<int>q;

        for(int i = 0 ; i < indegree.size() ; i++)
        {
            if(indegree[i]==0)
            {
                q.push(i);
                vis[i] = 1;
            }
        }

        int count_of_finished_courses = 0;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();
            count_of_finished_courses++;
            for(int i = 0 ; i < prerequisites.size() ; i++)
            {
                if(prerequisites[i][0] == node)indegree[prerequisites[i][1]]--;
                if(indegree[prerequisites[i][1]] == 0 and !vis[prerequisites[i][1]])
                {
                    // q.push(indegree[prerequisites[i][1]]);
                    q.push(prerequisites[i][1]);
                    vis[prerequisites[i][1]] = 1;
                }
            }
        }
        return count_of_finished_courses==numCourses ? true:false;
    }
};