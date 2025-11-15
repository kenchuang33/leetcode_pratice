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
int main() {
    Solution sol;

    // 測資 1：基本測試
    vector<int> candidates1 = {2, 3, 6, 7};
    int target1 = 7;
    vector<vector<int>> result1 = sol.combinationSum(candidates1, target1);
    cout << "Testcase 1:" << endl;
    for (const auto& combo : result1) {
        for (int num : combo) cout << num << " ";
        cout << endl;
    }

    // 測資 2：沒有解的情況
    vector<int> candidates2 = {5, 10};
    int target2 = 3;
    vector<vector<int>> result2 = sol.combinationSum(candidates2, target2);
    cout << "\nTestcase 2:" << endl;
    for (const auto& combo : result2) {
        for (int num : combo) cout << num << " ";
        cout << endl;
    }

    // 測資 3：單一數字重複使用
    vector<int> candidates3 = {1};
    int target3 = 3;
    vector<vector<int>> result3 = sol.combinationSum(candidates3, target3);
    cout << "\nTestcase 3:" << endl;
    for (const auto& combo : result3) {
        for (int num : combo) cout << num << " ";
        cout << endl;
    }

    // 測資 4：有多種組合
    vector<int> candidates4 = {2, 3, 5};
    int target4 = 8;
    vector<vector<int>> result4 = sol.combinationSum(candidates4, target4);
    cout << "\nTestcase 4:" << endl;
    for (const auto& combo : result4) {
        for (int num : combo) cout << num << " ";
        cout << endl;
    }

    return 0;
}
