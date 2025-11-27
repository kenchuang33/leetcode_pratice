// Subsets II
#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>> res;
        vector<int> path;
        backtracking(nums, res, path, 0);
        return res;
    }

    void backtracking(vector<int>& nums, vector<vector<int>>& res, vector<int>& path, int start)
    {
        res.push_back(path);

        for(int i=start; i<nums.size(); i++)
        {

            if( i > start && nums[i]==nums[i-1]) continue; //i > start：表示是同一層的後面幾個選擇（不是遞迴後的下一層）
            path.push_back(nums[i]);
            backtracking(nums, res, path, i+1);
            path.pop_back();
        }
    }
};