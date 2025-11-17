// Rotate Image

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();

        // Step 1: 轉置矩陣（沿主對角線交換）
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                swap(matrix[i][j], matrix[j][i]);
            }
        }

        // Step 2: 每一列 reverse（左右翻轉）
        for (int i = 0; i < n; ++i) {
            reverse(matrix[i].begin(), matrix[i].end());
        }
    }
};

class Solution1 {
public:
    void rotate(vector<vector<int>>& matrix) {

        int n = matrix.size();

        for (int layer = 0; layer < n / 2; ++layer) {
        // 處理每一圈
        for (int i = layer; i < n - 1 - layer; ++i) {
            // 暫存 top
            int top = matrix[layer][i];

            // 左 → 上
            matrix[layer][i] = matrix[n - 1 - i][layer];

            // 下 → 左
            matrix[n - 1 - i][layer] = matrix[n - 1 - layer][n - 1 - i];

            // 右 → 下
            matrix[n - 1 - layer][n - 1 - i] = matrix[i][n - 1 - layer];

            // top → 右
            matrix[i][n - 1 - layer] = top;
        }
    }
    }
};

int main() {
    Solution sol;
    
    vector<vector<int>> matrix = {
        {1,  2,  3},
        {4,  5,  6},
        {7,  8,  9}
    };

    sol.rotate(matrix);

    for (auto& row : matrix) {
        for (int num : row) cout << num << " ";
        cout << endl;
    }

    return 0;
}
