// Unique Paths
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int uniquePaths(int m, int n) {
        // 需要有特定的順序除(下面由小到大)，才不會有無法整除的問題
        unsigned long long top=1;
        unsigned long long down=1;
        int times; 
        unsigned long long ans=1;
        times=min(m-1,n-1);

        for(int i=0; i<times; i++)
        {
            ans=ans*((m+n-2)-i)/(i+1);
        }
        return ans;
    }
};

class Solution1 {
public:
    int uniquePaths(int m, int n) {
    //    dp 
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int row=0; row<m; row++) dp[row][0]=1;
        for(int col=0; col<n; col++) dp[0][col]=1;

        for(int row=1; row<m; row++)
        {
            for(int col=1; col<n; col++)
            {
                dp[row][col]= dp[row-1][col]+ dp[row][col-1];
            }
        }

        return dp[m-1][n-1];
    }
};

class Solution2 {
public:
    int uniquePaths(int m, int n) {
    // 1D dp 因為每一次需要的是左邊和上面的，把他想成複製一份上面的，再加上左邊的
     
        vector<int> dp(n, 1);

        for(int row=1; row<m; row++)
        {
            for(int col=1; col<n; col++)
            {
                dp[col]= dp[col-1]+ dp[col];
            }
        }

        return dp[n-1];
    }
};
int main() {
    Solution sol;
    Solution1 sol1;
    Solution2 sol2;

    vector<pair<int,int>> tests = {
        {1, 1},   // 最小值
        {1, 10},  // 單行
        {10, 1},  // 單列
        {2, 2},
        {3, 3},
        {3, 7},
        {7, 3},
        {16, 16},
        {23, 12},
        {12, 23},
        {50, 1},  // 大數單列
        {1, 50},  // 大數單行
        {10, 10}, // 方陣
        {20, 15}, // 混合
        {100, 1}, // 你需要測 overflow 相關
        {1, 100},
        {15, 15}  // 中等邊界
    };

    for (auto &t : tests) {
        int m = t.first;
        int n = t.second;

        int r  = sol.uniquePaths(m, n);
        int r1 = sol1.uniquePaths(m, n);
        int r2 = sol2.uniquePaths(m, n);

        cout << "m=" << m << ", n=" << n << endl;
        cout << "  Combinatorics: " << r << endl;
        cout << "  2D DP:         " << r1 << endl;
        cout << "  1D DP:         " << r2 << endl;
        cout << "-----------------------------" << endl;
    }
}





