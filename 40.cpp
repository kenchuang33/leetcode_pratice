// Combination Sum II
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
class Solution {
public:

    

    void backtracking(vector<int>& candidates, int target, int start, vector<int>& path ,vector<vector<int>>& res)
    {
        if(target==0)
        {
            res.push_back(path); 
            return;
        }
        if(target<0)
        {
            return;
        }

        for(int i =start; i<candidates.size(); i++)
        {
            if (i > start && candidates[i] == candidates[i-1]) continue;//同一層重複的可以跳過 因為我接下來有的選項跟前面的選項也都有 

            path.push_back(candidates[i]);
            backtracking(candidates, target-candidates[i], i+1, path, res);
            path.pop_back();
        }
    }
    
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    
        sort(candidates.begin(), candidates.end());
        vector<int> path;
        vector<vector<int>> res;  

        backtracking(candidates, target, 0, path, res);
        return res;



    }
};

int main() {
    Solution sol;

    vector<int> candidates = {1, 2, 2, 2, 2, 4};
    int target1 = 5;
    int target2 = 6;
    int target3 = 7;
    int target4 = 8;

    auto print = [](vector<vector<int>>& res) {
        for (auto& combo : res) {
            for (int n : combo) cout << n << " ";
            cout << endl;
        }
        cout << "--------" << endl;
    };

    cout << "Target = 5" << endl;
    auto res1 = sol.combinationSum2(candidates, 5);
    print(res1);

    cout << "Target = 6" << endl;
    auto res2 = sol.combinationSum2(candidates, 6);
    print(res2);

    cout << "Target = 7" << endl;
    auto res3 = sol.combinationSum2(candidates, 7);
    print(res3);

    cout << "Target = 8" << endl;
    auto res4 = sol.combinationSum2(candidates, 8);
    print(res4);

    return 0;
}





