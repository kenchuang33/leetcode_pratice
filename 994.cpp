//Rotting Oranges
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        queue<pair<int,int>> q;
        int fresh = 0;

        // 初始化
        for (int r = 0; r < rows; ++r) {
            for (int c = 0; c < cols; ++c) {
                if (grid[r][c] == 2) q.push({r, c});
                if (grid[r][c] == 1) fresh++;
            }
        }

        if (fresh == 0) return 0; // 沒有新鮮橘子

        int minutes = -1;
        vector<vector<int>> dirs = {{1,0}, {-1,0}, {0,1}, {0,-1}};

        // BFS
        while (!q.empty()) {
            int size = q.size();
            minutes++;

            for (int i = 0; i < size; ++i) {
                auto [r, c] = q.front();
                q.pop();

                for (auto& d : dirs) {
                    int nr = r + d[0];
                    int nc = c + d[1];

                    if (nr >= 0 && nc >= 0 && nr < rows && nc < cols && grid[nr][nc] == 1) {
                        grid[nr][nc] = 2;
                        fresh--;
                        q.push({nr, nc});
                    }
                }
            }
        }

        return (fresh == 0) ? minutes : -1;
    }
};

int main() {
    Solution sol;

    vector<vector<int>> grid1 = {
        {2,1,1},
        {1,1,0},
        {0,1,1}
    };
    cout << "Test 1: " << sol.orangesRotting(grid1) << endl;
    // ✅ 預期輸出：4
    // 解釋：需要 4 分鐘所有橘子都腐爛。

    vector<vector<int>> grid2 = {
        {2,1,1},
        {0,1,1},
        {1,0,1}
    };
    cout << "Test 2: " << sol.orangesRotting(grid2) << endl;
    // ✅ 預期輸出：-1
    // 解釋：有些橘子永遠無法被傳染。

    vector<vector<int>> grid3 = {
        {0,2}
    };
    cout << "Test 3: " << sol.orangesRotting(grid3) << endl;
    // ✅ 預期輸出：0
    // 解釋：沒有新鮮橘子，時間為 0。

    vector<vector<int>> grid4 = {
        {1}
    };
    cout << "Test 4: " << sol.orangesRotting(grid4) << endl;
    // ✅ 預期輸出：-1
    // 解釋：單一新鮮橘子，永遠不會腐爛。

    vector<vector<int>> grid5 = {
        {2,1,1},
        {1,1,1},
        {0,1,2}
    };
    cout << "Test 5: " << sol.orangesRotting(grid5) << endl;
    // ✅ 預期輸出：2
    // 解釋：兩個腐爛橘子從兩邊同時傳染，最快 2 分鐘。
}
