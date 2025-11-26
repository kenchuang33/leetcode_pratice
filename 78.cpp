// Subsets
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> path;
        

        backtracking(nums, 0, path, res);

        return res;
    }
    void backtracking(vector<int>& nums, int start, vector<int> &path, vector<vector<int>> &res)
    {
        
        res.push_back(path);

        for(int i=start; i<nums.size(); i++)
        {
            path.push_back(nums[i]);
            backtracking(nums ,i+1 ,path ,res);
            path.pop_back();
        }

    }
};
void printResult(const vector<vector<int>>& res) {
    cout << "[\n";
    for (const auto& v : res) {
        cout << "  [ ";
        for (int n : v) cout << n << " ";
        cout << "]\n";
    }
    cout << "]\n\n";
}

int main() {
    Solution s;

    // Testcase 1：基本
    vector<int> nums1 = {1, 2, 3};
    cout << "Testcase 1: {1,2,3}\n";
    printResult(s.subsets(nums1));

    // Testcase 2：單一元素
    vector<int> nums2 = {5};
    cout << "Testcase 2: {5}\n";
    printResult(s.subsets(nums2));

    // Testcase 3：空陣列
    vector<int> nums3 = {};
    cout << "Testcase 3: {}\n";
    printResult(s.subsets(nums3));

    // Testcase 4：包含負數
    vector<int> nums4 = {-1, 0, 1};
    cout << "Testcase 4: {-1,0,1}\n";
    printResult(s.subsets(nums4));

    // Testcase 5：四個元素（測試較大狀況）
    vector<int> nums5 = {1, 2, 3, 4};
    cout << "Testcase 5: {1,2,3,4}\n";
    printResult(s.subsets(nums5));

    return 0;
}