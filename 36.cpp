//Valid Sudoku
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows= board.size();
        int cols= board[0].size();


        for(int i=0; i<rows; i++)
        {
            unordered_map<char,int> rc1;
            for(int j=0;j<cols; j++)
            {
                char c=board[i][j];
                if (c != '.') rc1[c]++;
                if (rc1[c]>1) return false;
            }
        }

        for(int i=0; i<cols; i++)
        {
            unordered_map<char,int> rc2;
            for(int j=0;j<rows; j++)
            {
                char c=board[j][i];
                if (c != '.') rc2[c]++;
                if (rc2[c]>1) return false;
            }
        }

        for(int i =0 ; i<3; i++)
        {
            for(int j=0; j<3; j++)
            {
                unordered_map<char,int> rc3;
                for(int r=i*3; r<(i+1)*3; r++)
                {
                    for(int c=j*3; c<(j+1)*3; c++)
                    {

                        char cc=board[r][c];
                        if (cc != '.') rc3[cc]++;
                        if (rc3[cc]>1) return false;
                    }
                }
            }
        }
        return true;

    }
};

class Solution1 {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        bool row[9][9] = {false};
        bool col[9][9] = {false};
        bool box[9][9] = {false};

        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                char c = board[i][j];
                if (c == '.') continue;

                int num = c - '1'; // '1'->0, '9'->8
                int boxIndex = (i / 3) * 3 + (j / 3);

                if (row[i][num] || col[j][num] || box[boxIndex][num])
                    return false;

                row[i][num] = col[j][num] = box[boxIndex][num] = true;
            }
        }
        return true;
    }
};

// ================= 測試區 =================
int main() {
    vector<vector<char>> validBoard = {
        {'5','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    vector<vector<char>> invalidBoard = {
        {'8','3','.','.','7','.','.','.','.'},
        {'6','.','.','1','9','5','.','.','.'},
        {'.','9','8','.','.','.','.','6','.'},
        {'8','.','.','.','6','.','.','.','3'},
        {'4','.','.','8','.','3','.','.','1'},
        {'7','.','.','.','2','.','.','.','6'},
        {'.','6','.','.','.','.','2','8','.'},
        {'.','.','.','4','1','9','.','.','5'},
        {'.','.','.','.','8','.','.','7','9'}
    };

    Solution solA;
    Solution1 solB;

    cout << "Solution A (map):" << endl;
    cout << "合法棋盤: " << (solA.isValidSudoku(validBoard) ? "✔️ Valid" : "❌ Invalid") << endl;
    cout << "不合法棋盤: " << (solA.isValidSudoku(invalidBoard) ? "✔️ Valid" : "❌ Invalid") << endl;

    cout << "\nSolution B (bool array):" << endl;
    cout << "合法棋盤: " << (solB.isValidSudoku(validBoard) ? "✔️ Valid" : "❌ Invalid") << endl;
    cout << "不合法棋盤: " << (solB.isValidSudoku(invalidBoard) ? "✔️ Valid" : "❌ Invalid") << endl;

    return 0;
}