// 
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    vector<vector<string>> res;
    int n;

    vector<vector<string>> solveNQueens(int n) 
    {
        this->n = n;
        vector<int> path;                // path[row] = col 放皇后的地方
        vector<bool> cols(n, false);     // col 是否有皇后
        vector<bool> diag1(2*n, false);  // r - c + n
        vector<bool> diag2(2*n, false);  // r + c

        backtracking(0, path, cols, diag1, diag2);
        return res;
    }

    void backtracking(int row,
                      vector<int>& path,
                      vector<bool>& cols,
                      vector<bool>& diag1,
                      vector<bool>& diag2)
    {
        // 如果 row == n，代表 n 列都放完了
        if (row == n)
        {
            res.push_back(buildBoard(path));
            return;
        }

        for (int col = 0; col < n; col++)
        {
            // 1. 檢查同欄
            if (cols[col]) continue;

            // 2. 檢查主對角線 (r - c)
            if (diag1[row - col + n]) continue;

            // 3. 檢查副對角線 (r + col)
            if (diag2[row + col]) continue;

            // 可以放皇后 → 先做標記（佔用）
            cols[col] = true;
            diag1[row - col + n] = true;
            diag2[row + col] = true;
            path.push_back(col);

            // 放下一列
            backtracking(row + 1, path, cols, diag1, diag2);

            // 回溯（撤銷）
            path.pop_back();
            cols[col] = false;
            diag1[row - col + n] = false;
            diag2[row + col] = false;
        }
    }

    vector<string> buildBoard(vector<int>& path)
    {
        vector<string> board(n, string(n, '.'));
        for (int r = 0; r < n; r++)
        {
            board[r][path[r]] = 'Q';
        }
        return board;
    }
};
