// Longest Common Subsequence
#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        
        if(text2.size()>text1.size()) swap(text1, text2);

        int n = text1.size();
        int m = text2.size();

        vector<vector<int>> dp(m+1, vector<int> (n+1, 0));


        for(int i=1; i<m+1; i++)
        {
            for(int j=1; j<n+1; j++)
            {
                if(text1[j-1]==text2[i-1]) dp[i][j]=dp[i-1][j-1]+1;
                else dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }
        return dp[m][n];
    }
};

class   Solution1 {
public:
// 1D DP array optimization
    int longestCommonSubsequence(string text1, string text2) {
        
        if(text2.size()>text1.size()) swap(text1, text2);
        int m = text2.size();
        int n = text1.size();

        vector<int> dp(n+1, 0);
        int prev;

        for(int i=1; i<m+1; i++)
        {
            prev=0;
            for(int j=1; j<n+1; j++)
            {
                int temp=dp[j];
                if(text1[j-1]==text2[i-1]) dp[j]=prev+1;
                else dp[j]=max(dp[j],dp[j-1]);
                prev=temp;
            }
        }
        return dp[n];
    }
};
