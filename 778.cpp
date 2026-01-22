// Swim in Rising Water
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    
    vector<pair<int, int>> dir={{1,0},{0,1}, {-1,0},{0,-1}};

    int swimInWater(vector<vector<int>>& grid) {
        priority_queue< pair<int, pair<int, int>>, 
                        vector<pair<int, pair<int, int>>>,
                        greater<pair<int, pair<int, int>>>> pq;

        int n=grid.size();
        vector<vector<bool>> visited(n,vector<bool>(n, false));


        pq.push({grid[0][0],{0,0}});
        visited[0][0] = true;

         while(!pq.empty())
         {
            auto [h, pos]=pq.top();
            auto [x, y]=pos;
            pq.pop();
            
            // if(visited[x][y]) continue;
            // visited[x][y] = true;


            if(x==n-1 && y==n-1) return h;

            for(auto d: dir)
            {
                int nx=x+d.first;
                int ny=y+d.second;

                if(nx>=0 && nx<n && ny>=0 && ny<n && visited[nx][ny]!=true)
                {
                    visited[nx][ny] = true;
                    pq.push({max( h,grid[nx][ny]),{nx, ny}});
                }
            }
         }
         return 0;
    }
};