// Course Schedule II
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses, 0);

        for(auto edge:prerequisites)
        {
            adj[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
        }

        queue<int> q;
        for(int i=0; i<indegree.size(); i++)
        {
            if (indegree[i]==0) q.push(i);
        }

        vector<int> result;
        while(!q.empty())
        {
            int cur=q.front();
            q.pop();
            result.push_back(cur);

            for(auto next:adj[cur])
            {
                indegree[next]--;
                if(indegree[next]==0) q.push(next);
            }

        }

        if(result.size()==numCourses) return result;
        else return {};

    }
};