// Jump Game
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int far=0;
       

        for(int i=0; i<n; i++)
        {
            if (i>far) return false; //走不到這邊
            far=max(far,i+nums[i]);

        }
        return true;
    }
};
int main() {
    Solution sol;

    vector<vector<int>> tests = {
        {2,3,1,1,4},        // ✔ 可以跳到終點（經典案例）
        {3,2,1,0,4},        // ✘ 卡在 0，不能到終點
        {0},                // ✔ 單一元素，起點就是終點
        {1,0,1,0},          // ✘ 卡在 index=1，後面都到不了
        {2,0,0},            // ✔ 可以跳超過
        {0,1},              // ✘ 不能往前跳
        {5,4,3,2,1,0,0},    // ✔ 一開始就能跳很遠
        {1,2,3},            // ✔ 正常可以到終點
        {2,5,0,0},          // ✔ 可以跳到第 1 個再跳很遠
        {1,1,0,1},          // ✘ 卡住
        {1,2,0,1,0,4},      // ✔ 只要不被 0 卡住就行
        {2,0,2,0,1},        // ✔ 多次跳接力
    };

    for (int i = 0; i < tests.size(); i++) {
        bool result = sol.canJump(tests[i]);
        cout << "Test " << i+1 << ": ";
        for (int n : tests[i]) cout << n << " ";
        cout << " → " << (result ? "true" : "false") << endl;
    }

    return 0;
}