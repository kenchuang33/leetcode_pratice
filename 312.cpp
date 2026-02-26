// Burst Balloons
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        // 想成最後一個氣球pop，而不是先pop哪一個氣球
        int n = nums.size();
        // 1. 加上邊界，簡化邊緣計算
        vector<int> balloons(n + 2, 1);
        for (int i = 0; i < n; i++) {
            balloons[i + 1] = nums[i];
        }

        // 2. dp[i][j] 表示戳破 (i, j) 區間內所有氣球的最大金幣
        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));

        // 3. 區間長度 len 從 1 開始到 n
        for (int len = 1; len <= n; len++) {
            // i 為左端點
            for (int i = 1; i <= n - len + 1; i++) {
                int j = i + len - 1; // j 為右端點
                // dp[i][j]
                // 遍歷區間內最後一個被戳破的氣球 k
                for (int k = i; k <= j; k++) {
                    dp[i][j] = max(dp[i][j], 
                        dp[i][k - 1] + 
                        balloons[i - 1] * balloons[k] * balloons[j + 1] + 
                        dp[k + 1][j]);
                }
            }
        }

        return dp[1][n];
    }
};