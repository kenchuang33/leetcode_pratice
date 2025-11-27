// Word Search
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        int rows=board.size();
        int cols=board[0].size();
        bool res=false;
        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if (board[i][j]==word[0]) 
                {
                    res=( res || dfs(board, word, i, j, 0));
                }
            }
        }
        return  res;
        
    }
    bool dfs(vector<vector<char>>& board, string& word, int row, int col, int index) {
        if (board[row][col] != word[index]) return false;
        if (index == word.size() - 1) return true;

        char temp = board[row][col];
        board[row][col] = '.'; // 標記為已使用

        vector<pair<int, int>> dirs = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (auto [dx, dy] : dirs) {
            int nx = row + dx;
            int ny = col + dy;

            if (nx >= 0 && nx < board.size() && ny >= 0 && ny < board[0].size()) {
                if (dfs(board, word, nx, ny, index + 1)) {
                    board[row][col] = temp; // 還原
                    return true;
                }
            }
        }

        board[row][col] = temp; // 還原
        return false;
    }
};