// jump game 2 
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    int jump(vector<int>& nums) {
        int n=nums.size();
        vector<int> res(n,999999);
        res[0]=0;

        for(int i=0; i<n-1; i++)
        {
            for(int j=1; j<=nums[i]; j++)
            {
                int cur_min=res[i]+1;
                if(i+j>=n) break;
                res[i+j]=min(cur_min,res[i+j]);
            }
        }

        return res[n-1];
    }
};

class Solution2 {
public:
// greedy way 每一次都看最遠可以跳到哪裡，並在這一段選一個最遠的當作下一次跳躍的點，並一直重複
    int jump(vector<int>& nums) {
        int n = nums.size();
        int jumps = 0, farthest = 0, curEnd = 0;//farthest是比較每一格能走最遠的是多遠i + nums[i] ， curEnd是到最遠的距離

        // 思路為我先知道我這一跳能跳到多遠的距離(farthest)，代表這段curEnd=farthest距離裡面，我可以選一個i + nums[i]最大的值，他可以讓我下一步跳最遠
        // 當我能夠挑選最遠距離的扣打已經到達，我能跳的最遠距離的時候，
    

        for (int i = 0; i < n - 1; i++) {
            farthest = max(farthest, i + nums[i]);//沒有初始化更新farthest是因為當後來的能到最遠的距離都沒有更遠的時候 會變成max(farthest, farthest + nums[i])

            if (i == curEnd) {
                jumps++;
                curEnd = farthest;
            }
        }

        return jumps;
    }
};
int main() {
    Solution dpSol;
    Solution2 greedySol;

    vector<vector<int>> testcases = {
        {2, 3, 1, 1, 4},     // 最佳解為 2（0→1→4）
        {2, 1},              // 最佳解為 1（0→1）
        {1, 1, 1, 1},        // 最佳解為 3（每次只能跳一步）
        {5, 4, 3, 2, 1, 0, 0}, // 到不了最後一格（特殊情況，跳不到）
        {1, 2, 3},           // 最佳解為 2（0→1→3）
        {10, 9, 8, 7, 6, 1, 0, 0}, // 最佳解為 1（第一跳就到終點）
        {1, 3, 2, 1, 0, 4},  // 無法到終點
        {1},                 // 只有一個元素，不用跳（0 次）
        {1, 1, 1, 1, 1, 1, 1, 1, 1, 1} // 最佳解為 9
    };

    for (int i = 0; i < testcases.size(); ++i) {
        vector<int> nums = testcases[i];
        int dpAns = dpSol.jump(nums);
        int greedyAns = greedySol.jump(nums);
        cout << "Test case " << i + 1 << ": ";
        for (int num : nums) cout << num << " ";
        cout << "\n  DP Answer: " << dpAns << "\n  Greedy Answer: " << greedyAns << endl;
        cout << (dpAns == greedyAns ? "  ✅ Match\n" : "  ❌ Mismatch!\n");
        cout << "-------------------------------" << endl;
    }

    return 0;
}

