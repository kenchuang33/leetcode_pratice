// Search a 2D Matrix
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows=matrix.size();
        int cols=matrix[0].size();

        int top=0;
        int down=rows-1;
        int rowmid;

        while(top<=down)
        {
            rowmid=(top+down)/2;
            if( target >= matrix[rowmid][0] && target  <= matrix[rowmid][cols-1] ) break;

            if ( target > matrix[rowmid][0]) top = rowmid+1;
            else if (target < matrix[rowmid][0]) down = rowmid-1;
        }

        int l=0;
        int r=cols-1;
        int colmid;
        while(l<=r)
        {
            colmid=(l+r)/2;
            if ( target > matrix[rowmid][colmid]) l = colmid+1;
            else if (target < matrix[rowmid][colmid]) r = colmid-1;
            else return true;
        }

        return false;


    }
};

class Solution1 {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {

        int rows=matrix.size();
        int cols=matrix[0].size();
        int h=0;
        int d=rows*cols-1;

        while(h<=d)
        {
            int mid=(h+d)/2;
            int row=mid / cols;
            int col=mid % cols;

            if(target==matrix[row][col]) return true;

            if(target > matrix[row][col]) h=mid+1;
            else d=mid-1;
        }
        
        return false;


    }
};
int main() {
    Solution sol;
    Solution1 sol1;

    vector<vector<int>> matrix1 = {
        {1, 3, 5, 7},
        {10, 11, 16, 20},
        {23, 30, 34, 60}
    };

    cout << sol.searchMatrix(matrix1, 3) << endl;   // true
    cout << sol.searchMatrix(matrix1, 13) << endl;  // false
    cout << sol1.searchMatrix(matrix1, 3) << endl;  // true
    cout << sol1.searchMatrix(matrix1, 13) << endl; // false

    vector<vector<int>> matrix2 = {
        {1}
    };
    cout << sol.searchMatrix(matrix2, 1) << endl;   // true
    cout << sol.searchMatrix(matrix2, 0) << endl;   // false
    cout << sol1.searchMatrix(matrix2, 1) << endl;  // true
    cout << sol1.searchMatrix(matrix2, 2) << endl;  // false

    vector<vector<int>> matrix3 = {
        {1, 2, 3, 4}
    };
    cout << sol.searchMatrix(matrix3, 3) << endl;   // true
    cout << sol.searchMatrix(matrix3, 5) << endl;   // false
    cout << sol1.searchMatrix(matrix3, 4) << endl;  // true

    vector<vector<int>> matrix4 = {
        {1},
        {3},
        {5},
        {7}
    };
    cout << sol.searchMatrix(matrix4, 5) << endl;   // true
    cout << sol.searchMatrix(matrix4, 6) << endl;   // false
    cout << sol1.searchMatrix(matrix4, 7) << endl;  // true
    cout << sol1.searchMatrix(matrix4, 0) << endl;  // false

    return 0;
}
