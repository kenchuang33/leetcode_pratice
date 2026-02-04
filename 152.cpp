// Maximum Product Subarray
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
int maxProduct(vector<int>& nums) {
    if (nums.empty()) return 0;

    int res = nums[0];
    int curMax = nums[0];
    int curMin = nums[0];

    for (int i = 1; i < nums.size(); i++) {
        int n = nums[i];

        // 關鍵點：當遇到負數時，最大與最小會互換
        // 因為 最大 * 負 = 最小，最小 * 負 = 最大
        if (n < 0) {
            swap(curMax, curMin);
        }

        // 決定是否要「拋棄過去」從 n 重新開始
        curMax = max(n, curMax * n);
        curMin = min(n, curMin * n);

        // 隨時更新全局最高分
        res = max(res, curMax);
    }

    return res;
    }
};

class Solution1 {
public:
    int maxProduct(vector<int>& nums) {
        int res = nums[0]; // 儲存最終結果，初始化為第一個數
        int f = 1;         // 累乘器

        // --- 第一遍：從左往右掃描 ---
        for(auto n : nums) {
            if(n == 0) {
                f = 1;          // 遇到 0，連續子陣列中斷，重置累乘器為 1
                res = max(res, 0); // 確保 0 也有被列入最大值的考慮
            } else {
                f *= n;         // 累乘目前的數字
                res = max(res, f); // 更新全域最大值
            } 
        }

        // --- 第二遍：從右往左掃描 ---
        f = 1; // 重置累乘器
        for(int i = nums.size() - 1; i >= 0; i--) {
            if(nums[i] == 0) {
                f = 1;          // 遇到 0，重置累乘器
                res = max(res, 0); 
            } else {
                f *= nums[i];   // 從右端開始累乘
                res = max(res, f); 
            }    
        }
        return res;
    }
};