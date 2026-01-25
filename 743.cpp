// Network Delay Time
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        
        unordered_map<int, int> graph;
        priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        
        pq.push({0,k});
        
        while(!pq.empty() )
        {
            
            auto [dist , source] = pq.top();
            pq.pop();
        
            if (graph.count(source)) continue;
            // 如果這個點已經在 graph 裡了，代表我們之前已經找到更短的路徑並處理過了
            // 這次 pop 出來的是較長的路徑，必須跳過，否則會發生錯誤覆蓋            

            graph[source]=dist;
            
            for(auto edge: times)
            {
                if (edge[0]==source && !graph.count(edge[1])) pq.push({ dist+edge[2] , edge[1]});
            }
        }

        int ans=0;
        for(auto [x,y]:graph )
        {
            ans=max(ans,y);
        }

        return graph.size()==n ? ans :-1;
    }
};

class Solution1 {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 1. 建立鄰接表：source -> list of {target, weight}
        // 使用 vector<vector<...>> 比 map 快，因為點的編號是 1 到 n
        vector<vector<pair<int, int>>> adj(n + 1);
        for (auto& edge : times) {
            adj[edge[0]].push_back({edge[1], edge[2]});
        }

        unordered_map<int, int> graph; // 存放確定的 {點: 最短距離}
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        
        pq.push({0, k});
        
        while (!pq.empty()) {
            auto [dist, u] = pq.top();
            pq.pop();
            
            // 如果點 u 已經處理過，跳過
            if (graph.count(u)) continue;
            
            // 確定點 u 的最短路徑
            graph[u] = dist;
            
            // 2. 只遍歷點 u 的鄰居，效率大增！
            for (auto& edge : adj[u]) {
                int v = edge.first;
                int weight = edge.second;
                
                if (!graph.count(v)) {
                    pq.push({dist + weight, v});
                }
            }
        }

        int ans = 0;
        for (auto [node, d] : graph) {
            ans = max(ans, d);
        }

        return graph.size() == n ? ans : -1;
    }
};