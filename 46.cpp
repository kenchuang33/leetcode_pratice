// Permutations
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <set>

using namespace std;
class Solution {
public:
    set<vector<int>> rc;
    vector<vector<int>> res;
    vector<vector<int>> permute(vector<int>& nums) 
    {
        vector<int> path;
        unordered_map<int,int> um;
        backtracking(nums, 0, path, um);
        return res;
    }
    
    void backtracking(vector<int>& nums, int times, vector<int>& path, unordered_map<int,int>& um)
    {

        int n=nums.size();

        if(times==n)
        {
            // if(rc.find(path)==rc.end())
            // {
            //     rc.insert(path);
            //     res.push_back(path);
            //     return;
            // } 
            // 不需要以上這一段，因為已經確保他不會有相同的順序出現了
            res.push_back(path);
            return;
        }

        if(times>n) return;

        for(int i=0; i<n; i++)
        {
            if (um[nums[i]]==0)
            {
                um[nums[i]]++;
                path.push_back(nums[i]);
                backtracking(nums, times+1, path, um);
            }
            else
            {
                continue;
            }
            um[nums[i]]--;
            path.pop_back();
        }


    }
};
class Solution2 {
public:
    vector<vector<int>> res;

    vector<vector<int>> permute(vector<int>& nums) {
        vector<bool> used(nums.size(), false); // 記錄每個 index 有沒有被使用
        vector<int> path;
        backtrack(nums, used, path);
        return res;
    }

    void backtrack(vector<int>& nums, vector<bool>& used, vector<int>& path) {
        if (path.size() == nums.size()) {
            res.push_back(path);
            return;
        }

        for (int i = 0; i < nums.size(); ++i) {
            if (used[i]) continue; // 如果這個 index 的值用過就跳過
            used[i] = true;
            path.push_back(nums[i]);
            backtrack(nums, used, path);
            path.pop_back();
            used[i] = false; // 回溯
        }
    }
};

int main() {
    Solution sol;
    vector<int> nums = {1, 2, 3}; // 測試用例：distinct 整數
    vector<vector<int>> result = sol.permute(nums);

    cout << "所有排列結果：" << endl;
    for (const auto& vec : result) {
        for (int num : vec) {
            cout << num << " ";
        }
        cout << endl;
    }

    return 0;
}
