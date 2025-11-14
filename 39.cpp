//Combination Sum
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> path;
        backtrack(candidates, target, 0, path, res);
        return res;
    }

    void backtrack(vector<int>& candidates, int target, int start,
                   vector<int>& path, vector<vector<int>>& res) {
        if (target == 0) {
            res.push_back(path);
            return;
        }
        if (target < 0) return;

        for (int i = start; i < candidates.size(); ++i) {  // 🔥 重點：從 start 開始
            
            // vector<int> Newpath = path;
            // Newpath.push_back(candidates[i]);
            // backtrack(candidates, target - candidates[i], i, Newpath, res); 
            
            path.push_back(candidates[i]);
            backtrack(candidates, target - candidates[i], i, path, res); // 可重複使用，所以還是 i
            path.pop_back();



        }
    }
};
