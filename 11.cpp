//Container With Most Water
#include <climits>
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;

        int max_region=0;

        while(l!=r)
        {   
            int r_height=height[r];
            int l_height=height[l];
            int height=min(r_height,l_height);
            int region=height*(r-l);
            max_region=max(max_region,region);

            if (r_height>l_height)
            {
                l++;
            }
            else
            {
                r--;
            }
        }

        return max_region;
    }
};
int main() {
    Solution sol;

    // 測試案例 1：官方經典例子
    vector<int> height1 = {1,8,6,2,5,4,8,3,7};
    cout << "Test 1 result: " << sol.maxArea(height1) << endl; // 期望輸出：49

    // 測試案例 2：高度遞增
    vector<int> height2 = {1,2,3,4,5};
    cout << "Test 2 result: " << sol.maxArea(height2) << endl; // 期望輸出：6

    // 測試案例 3：高度相同
    vector<int> height3 = {5,5,5,5,5};
    cout << "Test 3 result: " << sol.maxArea(height3) << endl; // 期望輸出：20

    // 測試案例 4：只有兩根柱子
    vector<int> height4 = {2,10};
    cout << "Test 4 result: " << sol.maxArea(height4) << endl; // 期望輸出：2

    // 測試案例 5：鋸齒形高度
    vector<int> height5 = {1,3,2,5,25,24,5};
    cout << "Test 5 result: " << sol.maxArea(height5) << endl; // 期望輸出：24

    return 0;
}
