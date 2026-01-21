// Pacific Atlantic Water Flow
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        

        vector<vector<bool>> pacific(heights.size(),vector<bool>(heights[0].size(), false));
        vector<vector<bool>> atlantic(heights.size(),vector<bool>(heights[0].size(), false));

        vector<vector<int>> ans;

        for(int i = 0; i<heights.size(); i++)
        {
            bfs(i, 0, pacific, heights);
        }

        for(int i = 0; i<heights[0].size(); i++)
        {
            bfs(0, i, pacific, heights);
        }

        for(int i = 0; i<heights.size(); i++)
        {
            bfs(i, heights[0].size()-1, atlantic, heights);
        }

        for(int i = 0; i<heights[0].size(); i++)
        {
            bfs(heights.size()-1, i, atlantic, heights);
        }


        for(int i=0; i<heights.size(); i++)
        {
            for(int j=0; j<heights[0].size(); j++)
            {
                if(pacific[i][j]==true && atlantic[i][j]==true ) ans.push_back({i,j});
            }
        }

        return ans;
    }

    void bfs(int row, int col, vector<vector<bool>>& map, vector<vector<int>>& heights)
    {
        if (map[row][col]) return;

        queue< vector<int> > q;
        q.push({row ,col});
        map[row][col]=true;
        
        int r=map.size();
        int c=map[0].size();
        
        vector<vector<int>> dir = {{1,0} ,{-1,0} ,{0,1} ,{0,-1}};

        while (!q.empty())
        {
            
            int x =q.front()[0];
            int y =q.front()[1];
            
            q.pop();

            for(auto v:dir)
            {
                int nx=x+v[0];
                int ny=y+v[1];

                if(nx>=0 && nx<r && ny>=0 && ny<c && map[nx][ny]==false && (heights[nx][ny]>=heights[x][y]) )
                {
                    map[nx][ny]=true;
                    q.push({nx, ny});
                }
            }

        }


    }
};

class Solution1 {
public:
// 正解
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        if (heights.empty() || heights[0].empty()) return {};
        
        int rows = heights.size();
        int cols = heights[0].size();
        
        vector<vector<bool>> pacific(rows, vector<bool>(cols, false));
        vector<vector<bool>> atlantic(rows, vector<bool>(cols, false));
        
        queue<pair<int, int>> qP, qA;

        // 1. 準備邊界起點
        for (int i = 0; i < rows; i++) {
            // 太平洋左邊界
            qP.push({i, 0});
            pacific[i][0] = true;
            // 大西洋右邊界
            qA.push({i, cols - 1});
            atlantic[i][cols - 1] = true;
        }
        for (int j = 0; j < cols; j++) {
            // 太平洋上邊界
            qP.push({0, j});
            pacific[0][j] = true;
            // 大西洋下邊界
            qA.push({rows - 1, j});
            atlantic[rows - 1][j] = true;
        }

        // 2. 執行兩次 BFS (從海邊往山上爬)
        bfs(heights, qP, pacific);
        bfs(heights, qA, atlantic);

        // 3. 找出交集
        vector<vector<int>> ans;
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {
                if (pacific[i][j] && atlantic[i][j]) {
                    ans.push_back({i, j});
                }
            }
        }
        return ans;
    }

    void bfs(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited) {
        int rows = heights.size();
        int cols = heights[0].size();
        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        while (!q.empty()) {
            auto [currR, currC] = q.front();
            q.pop();
            
            for (auto& d : dirs) {
                int nr = currR + d.first;
                int nc = currC + d.second;
                
                // 條件：在範圍內、沒走過、且高度大於等於當前點（水往低處流，所以我們往高處爬）
                if (nr >= 0 && nr < rows && nc >= 0 && nc < cols && 
                    !visited[nr][nc] && heights[nr][nc] >= heights[currR][currC]) {
                    visited[nr][nc] = true; // 關鍵：入隊前就標記
                    q.push({nr, nc});
                }
            }
        }
    }
};