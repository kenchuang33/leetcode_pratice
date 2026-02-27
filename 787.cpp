// Cheapest Flights Within K Stops
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
public:
    // BFS
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        unordered_map<int, vector<vector<int>>> edge;
        for(auto& dir : flights)
        {
            vector<int> temp;
            temp.push_back(dir[1]);
            temp.push_back(dir[2]);

            edge[dir[0]].push_back(temp);
        }

        unordered_map<int, int> distance;
        for(int i=0; i<n; i++)
        {
            distance[i]=INT_MAX;
        }

        queue<vector<int>> q;

        q.push({src,0});
        distance[src]=0;
        
        while(k>=0 && !q.empty())
        {
            int len=q.size();
            for(int i=0; i<len; i++)
            {
                int node=q.front()[0];
                int cur_dist=q.front()[1];
                q.pop();

                for(auto& next:edge[node])
                {
                    if(cur_dist + next[1] < distance[next[0]] )
                    {
                        q.push({ next[0] , cur_dist + next[1] } );
                        distance[next[0]]=cur_dist + next[1];
                    }                    
                }
            }
            k--;
        }
        return distance[dst]==INT_MAX? -1 : distance[dst];
    }
};

class Solution_BFS {
public:
    // BFS with pruning
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 建立鄰接表
        vector<vector<pair<int, int>>> adj(n);
        for (auto& f : flights) {
            adj[f[0]].push_back({f[1], f[2]});
        }

        // 紀錄到每個點的最短距離
        vector<int> min_dist(n, INT_MAX);
        min_dist[src] = 0;

        queue<pair<int, int>> q; // {節點, 當前花費}
        q.push({src, 0});

        int stops = 0;
        // 轉機 k 次代表最多走 k+1 條邊
        while (!q.empty() && stops <= k) {
            int sz = q.size();
            // 處理當前這一層的所有節點
            for (int i = 0; i < sz; i++) {
                auto [curr, cost] = q.front();
                q.pop();

                for (auto& edge : adj[curr]) {
                    int next_node = edge.first;
                    int price = edge.second;

                    // 剪枝：只有找到更便宜的路徑才繼續搜尋
                    if (cost + price < min_dist[next_node]) {
                        min_dist[next_node] = cost + price;
                        q.push({next_node, min_dist[next_node]});
                    }
                }
            }
            stops++;
        }

        return min_dist[dst] == INT_MAX ? -1 : min_dist[dst];
    }
};

class Solution_BellmanFord {
public:
// Bellman-Ford 
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        // 初始化距離陣列
        vector<int> dist(n, 1e9); // 使用 1e9 避免 INT_MAX 相加溢位
        dist[src] = 0;

        // 進行 k+1 次鬆弛（最多走 k+1 條邊）
        for (int i = 0; i <= k; i++) {
            // 關鍵：必須使用暫存陣列，確保本輪更新不影響本輪其他計算
            vector<int> tmp = dist;
            for (auto& f : flights) {
                int u = f[0], v = f[1], price = f[2];
                // 如果起點 u 是可達的，嘗試更新終點 v
                if (dist[u] != 1e9) {
                    tmp[v] = min(tmp[v], dist[u] + price);
                }
            }
            dist = tmp; // 本輪結束後，將結果存回主陣列
        }

        return (dist[dst] == 1e9) ? -1 : dist[dst];
    }
};
