// Word Break
#include <vector>
#include <unordered_set>
#include <string>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_set<string> rc(wordDict.begin(), wordDict.end());

        int n=s.size();
        vector<bool> dp(n+1,false);
        dp[0]=true;

        for(int i=1; i<=n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(dp[j] && rc.count(s.substr(j, i-j))) //如果前半段可切開，檢查後半段是否是字典中的字
                {
                    dp[i]=true;
                    break;
                } 
            }
        }

        return dp[n];
    }
};


// dp[i]=dp[j-1] && rc.count(s.substr(j, i-j+1));