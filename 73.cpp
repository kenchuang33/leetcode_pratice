// Set Matrix Zeroes
#include <iostream>
#include <vector>

using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        // O(M+N)
        int rows=matrix.size();
        int cols=matrix[0].size();

        vector<bool> row(rows, false);
        vector<bool> col(cols, false);

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=true;
                    col[j]=true;
                }
            }
        }

        for(int i=0; i<rows; i++)
        {
            for(int j=0; j<cols; j++)
            {
                if(row[i]==true || col[j]==true)
                {
                   matrix[i][j]=0;
                }
            }
        }


    }
};
class Solution1 {
public:
// O(1)
    void setZeroes(vector<vector<int>>& matrix) {
        int rows=matrix.size();
        int cols=matrix[0].size();
        bool firstrow = false;
        bool firstcol = false;

        for(int i=0; i<rows; i++)
        {
            if (matrix[i][0]==0) firstcol=true;
        }

        for(int i=0; i<cols; i++)
        {
            if (matrix[0][i]==0) firstrow=true;
        }

        for(int i=1; i<rows; i++)
        {
            for(int j=1; j<cols; j++)
            {
                if(matrix[i][j]==0) 
                {
                    matrix[i][0]=0;
                    matrix[0][j]=0;
                }
            }
        }

        for(int i=1; i<rows; i++)
        {
            for(int j=1; j<cols; j++)
            {
                if(matrix[i][0]==0 || matrix[0][j]==0) matrix[i][j]=0;
            }
        }

        if (firstcol)
        {
            for(int i=0; i<rows; i++)
            {
                matrix[i][0]=0;
            }
        }
        if (firstrow)
        {
            for(int i=0; i<cols; i++)
            {
                matrix[0][i]=0;
            }
        }

    }
};
void printMatrix(vector<vector<int>>& matrix) {
    for (auto& row : matrix) {
        for (auto val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

int main() {
    Solution1 s;  // 或是用 Solution s;

    vector<vector<int>> matrix = {
        {1, 1, 1},
        {1, 0, 1},
        {1, 1, 1}
    };

    s.setZeroes(matrix);
    printMatrix(matrix);

    return 0;
}