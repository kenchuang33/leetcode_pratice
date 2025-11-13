//Search in Rotated Sorted Array

#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        //左邊和右邊只有一邊是正常的
        while(l<=r)
        {
            int mid=(l+r)/2;
            if (nums[mid]==target) return mid;

            if (nums[l]<=nums[mid]) //可能只有兩個數字
            {
                //左邊是正常的
                if (nums[l] <= target && target < nums[mid])//檢查過 target ！＝ nums[mid] 所以不用 <=
                {
                    //要找的值在左邊
                    r=mid-1;
                }
                else
                {
                    //要找的值在右邊
                    l=mid+1;
                }
            }
            else 
            {
                //右邊是正常的
                if (nums[mid] < target && target <= nums[r])
                {
                    //要找的值在右邊
                    l=mid+1;
                }
                else
                {
                    //要找的值在左邊
                    r=mid-1;
                }
            }

        }
        return -1;
    }
};
int main() {
    Solution sol;

    vector<pair<vector<int>, int>> test_cases = {
        {{4,5,6,7,0,1,2}, 0},
        {{4,5,6,7,0,1,2}, 3},
        {{1}, 0},
        {{1}, 1},
        {{5,1,3}, 5},
        {{5,1,3}, 3},
    };

    for (int i = 0; i < test_cases.size(); ++i) {
        auto& [nums, target] = test_cases[i];
        int result = sol.search(nums, target);
        cout << "Test case " << i+1 << ": ";
        cout << "search(" << target << ") → " << result << endl;
    }

    return 0;
}
