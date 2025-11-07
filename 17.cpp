//Letter Combinations of a Phone Number
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    // dfs+backtrack 把它想成在一個tree做dfs
    vector<string> ans;
    vector<string> Mapping={"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    void dfs(string &digits, int pos, string path)
    {
        //終止條件
        if (path.size()==digits.size()) 
        {
            ans.push_back(path);
            return;
        }
    
        for(char c : Mapping[digits[pos]-'0'])
        // 要注意把digits的char轉成int
        {
            path.push_back(c);
            dfs(digits,pos+1,path);
            path.pop_back();
        }

    }

    vector<string> letterCombinations(string digits) {
        ans.clear();
        if (digits.size()==0)
        {
            return ans;
        }
        
        dfs(digits,0,"");
        return ans;
    }
};

class Solution1 {
public:
    // 單純的recursion，從最底層慢慢加回上一層

    vector<string> Mapping={"","","abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};

    vector<string> Solve(string &digits, int i)
    {
        // 要注意終止條件的時候應該是要回傳一個空字串
        if (i==digits.size()) return {""};

        vector<string> rest= Solve(digits,i+1);

        vector<string> ans;

        for(char c : Mapping[digits[i]-'0'])
        {
            for (string s : rest)
            {
                ans.push_back(string(1, c) + s);
            }
        }

        return ans;

    }

    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        return Solve(digits,0);
    }
};

int main() {
    Solution sol;//dfs
    Solution1 sol1;//recursion

    vector<string> tests = {"", "2", "23", "79"};

    for (auto &digits : tests) {
        cout << "Input: \"" << digits << "\"\n";
        
        vector<string> res = sol1.letterCombinations(digits);

        cout << "Output size: " << res.size() << "\n";
        cout << "Combinations: ";
        if (res.empty()) {
            cout << "[]";
        } else {
            cout << "[";
            for (size_t i = 0; i < res.size(); ++i) {
                cout << "\"" << res[i] << "\"";
                if (i + 1 < res.size()) cout << ", ";
            }
            cout << "]";
        }
        cout << "\n----\n";
    }

    return 0;
}