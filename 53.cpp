// Maximum Subarray
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int n =nums.size();
        vector<int> dp(n);

        dp[0]=nums[0];
        int maxnum=dp[0];

        for(int i=1; i<n; i++)
        {
            dp[i]=max(nums[i],nums[i]+dp[i-1]);
            maxnum=max(maxnum,dp[i]);
        }
        
        return maxnum;
    }
};
int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {-2, 1, -3, 4, -1, 2, 1, -5, 4},  // 經典案例：答案 6
        {1},                              // 單元素：答案 1
        {5, 4, -1, 7, 8},                  // 全為正 -> 全部之和：23
        {-1},                             // 單個負數：答案 -1
        {-2, -3, -1, -5},                 // 全負數 -> 最大為 -1
        {8, -19, 5, -4, 20},              // 跨負數最大段：21
        {-2, 1},                          // 最佳為 1
        {2, -1, 2, 3, -9, 4},             // 多段選擇：6
    };

    for (int i = 0; i < tests.size(); i++) {
        cout << "Testcase " << i + 1 << ": ";
        for (int x : tests[i]) cout << x << " ";
        cout << "\nOutput = " << sol.maxSubArray(tests[i]) << "\n\n";
    }

    return 0;
}