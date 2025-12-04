// Palindrome Partitioning
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Solution {
public:
    
    vector<vector<string>> partition(string s) {
        int n=s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        for(int i =0; i<n; i++)
        {
            for(int j=0; j<n; j++)
            {
                dp[i][j]=isPalindrome(s,i,j);
            }
        }
        vector<string> path;
        vector<vector<string>> res;

        backtracking(s, 0, dp, path, res);

        return res;
    }

    bool isPalindrome(string s, int start, int end)
    {
        if (start > end) return false;
        if(start==end) return true;

        if (s[start]==s[end])
        {
          if((end-start)==1) return true;
          else return isPalindrome(s,start+1,end-1);  
        } 
        else return false;
    }

    void backtracking( string s, int start,  
                        vector<vector<bool>>& dp, 
                        vector<string>& path, 
                        vector<vector<string>>& res)
    {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }

        for(int i=start; i<s.size(); i++)
        {
            if(dp[start][i])
            {
                path.push_back(s.substr(start,i-start+1));
                backtracking(s, i+1, dp, path, res);
                path.pop_back();
            }
        }
    }


};


class Solution1 {
public:
    vector<vector<string>> partition(string s) {
        int n = s.size();
        vector<vector<bool>> dp(n, vector<bool>(n, false));

        // Step 1: 預處理 dp[i][j] 是否為回文
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j]) {
                    if (j - i <= 2) dp[i][j] = true;
                    else dp[i][j] = dp[i + 1][j - 1];
                }
            }
        }

        // Step 2: 開始 backtracking
        vector<vector<string>> res;
        vector<string> path;
        backtracking(0, s, dp, path, res);

        return res;
    }

    void backtracking(int start, string& s, vector<vector<bool>>& dp,
                      vector<string>& path, vector<vector<string>>& res) {
        if (start == s.size()) {
            res.push_back(path);
            return;
        }

        for (int end = start; end < s.size(); end++) {
            if (dp[start][end]) {
                // 切出這段是回文的字串
                path.push_back(s.substr(start, end - start + 1));
                backtracking(end + 1, s, dp, path, res);
                path.pop_back(); // 回溯
            }
        }
    }
};
