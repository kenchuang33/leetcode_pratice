//3Sum

#include <iostream>
#include <vector>
#include <array>
#include <set>
#include <unordered_set>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        //approach 1
        
        sort(nums.begin(), nums.end());
        
        int n=nums.size();
        vector<vector<int>> answer;
        if (n < 3) return answer;

        for(int i=0;i<n-2;i++)
        {   
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            if (nums[i]>0) break;
            int l=i+1;
            int r=n-1;


            while(l<r)
            {
                if (nums[i]+nums[l]+nums[r]==0)
                {
                    answer.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(nums[l]==nums[l-1] && l<r) l++;
                    while(nums[r]==nums[r+1] && l<r) r--;
                }
                else if (nums[i]+nums[l]+nums[r]>0)
                {
                    r--;
                    while(nums[r]==nums[r+1] && l<r) r--;
                }
                else
                {
                    l++;
                    while(nums[l]==nums[l-1]&& l<r) l++;
                }
            }

            
        }
        return answer;
    }

    vector<vector<int>> threeSum1(vector<int>& nums) {
        //approach 2
        int n = nums.size();
        vector<vector<int>> ans;
        if (n < 3) return ans;

        set<array<int,3>> uniq;              // 全域去重（字典序）
        for (int i = 0; i < n; ++i) {
            unordered_set<int> seen;         // 針對此 i 的 2Sum 加速
            for (int j = i + 1; j < n; ++j) {
                int need = -nums[i] - nums[j];
                if (seen.count(need)) {
                    array<int,3> t = {nums[i], nums[j], need};
                    sort(t.begin(), t.end()); // 三個數就地排序，固定成本
                    if (!uniq.count(t)) 
                    {
                        uniq.insert(t);
                        ans.push_back({t[0], t[1], t[2]});
                    }
                }
                seen.insert(nums[j]);
            }
        }
        return ans;
    }
};


int main() {
    Solution s;

    vector<vector<int>> testcases = {
        {-1, 0, 1, 2, -1, -4},   // 多組解
        {0, 1, 1},               // 沒有解
        {0, 0, 0},               // 一組 [0,0,0]
        {-2, -2, 0, 0, 2, 2},    // 一組 [-2,0,2]
        {-4, -1, -1, 0, 1, 2},   // 同樣是最常見例子
    };

    for (int t = 0; t < testcases.size(); ++t) {
        cout << "Testcase " << t + 1 << ": ";
        vector<vector<int>> result = s.threeSum(testcases[t]);

        cout << "[ ";
        for (auto &triplet : result) {
            cout << "[";
            for (int i = 0; i < triplet.size(); ++i) {
                cout << triplet[i];
                if (i < triplet.size() - 1) cout << ",";
            }
            cout << "] ";
        }
        cout << "]" << endl;
    }

    return 0;
}
