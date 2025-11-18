// Group Anagrams
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> rc;
        int n =strs.size();
        vector<vector<string>> res;

        for(int i=0; i<n; i++)
        {
            string temp=strs[i];
            sort(temp.begin(),temp.end());

            rc[temp].push_back(strs[i]);
        }

        for(auto [a,b] : rc)
        {
            res.push_back(b);
        }

        return res;
    }
};

class Solution1{
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> rc;

        for (const string& s : strs) {
            vector<int> count(26, 0);
            for (char c : s) {
                count[c - 'a']++;
            }

            // 將 count 轉成 key 字串
            string key;
            for (int i = 0; i < 26; ++i) {
                key += '#' + to_string(count[i]); // 加 '#' 是為了避免 11 與 1,1 混淆
            }

            rc[key].push_back(s);
        }

        vector<vector<string>> res;
        for (auto& [key, group] : rc) {
            res.push_back(move(group)); // move 可以微幅減少複製成本
        }

        return res;
    }
};

int main() {
    Solution sol;
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    vector<vector<string>> result = sol.groupAnagrams(input);
    
    for (const auto& group : result) {
        cout << "[ ";
        for (const auto& word : group) {
            cout << word << " ";
        }
        cout << "]\n";
    }

    return 0;
}
