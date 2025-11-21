// Spiral Matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) 
    {
        
         vector<int> res;
        int top=0;
        int right=matrix[0].size()-1;
        int bottom=matrix.size()-1;
        int left=0;

        while(left<= right && top<=bottom)
        {
            for(int i=left; i<=right; i++)
            {
                res.push_back(matrix[top][i]);
            }
            top++;

            for(int i=top; i<=bottom; i++)
            {
                res.push_back(matrix[i][right]);
            }
            right--;

            //已經經過一輪的 top++ 和 right-- 需要檢查
            if(top<=bottom)
            {
                for(int i=right ; i>=left; i--)
                {
                    res.push_back(matrix[bottom][i]);
                }
                bottom--;
            }

            if(left <= right)
            {
                for(int i=bottom ; i>=top; i--)
                {
                    res.push_back(matrix[i][left]);
                }
                left++;
            }
        }
        return res;
    }
};

void printResult(vector<int> result) {
    for (int num : result) cout << num << " ";
    cout << endl;
}

int main() {
    Solution sol;

    // 測資 1：3x3 正方形矩陣
    vector<vector<int>> matrix1 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9}
    };
    cout << "測資 1 預期: 1 2 3 6 9 8 7 4 5\n實際: ";
    printResult(sol.spiralOrder(matrix1));

    // 測資 2：3x4 橫向矩形
    vector<vector<int>> matrix2 = {
        {1,  2,  3,  4},
        {5,  6,  7,  8},
        {9, 10, 11, 12}
    };
    cout << "測資 2 預期: 1 2 3 4 8 12 11 10 9 5 6 7\n實際: ";
    printResult(sol.spiralOrder(matrix2));

    // 測資 3：4x3 直向矩形
    vector<vector<int>> matrix3 = {
        {1, 2, 3},
        {4, 5, 6},
        {7, 8, 9},
        {10,11,12}
    };
    cout << "測資 3 預期: 1 2 3 6 9 12 11 10 7 4 5 8\n實際: ";
    printResult(sol.spiralOrder(matrix3));

    // 測資 4：單列
    vector<vector<int>> matrix4 = {
        {1, 2, 3, 4, 5}
    };
    cout << "測資 4 預期: 1 2 3 4 5\n實際: ";
    printResult(sol.spiralOrder(matrix4));

    // 測資 5：單欄
    vector<vector<int>> matrix5 = {
        {1},
        {2},
        {3},
        {4},
        {5}
    };
    cout << "測資 5 預期: 1 2 3 4 5\n實際: ";
    printResult(sol.spiralOrder(matrix5));

    return 0;
}