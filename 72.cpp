//Edit Distance
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
//bottom up 
public:
    int minDistance(string word1, string word2) {
        
        int col=word1.size()+1;
        int row=word2.size()+1;

        vector<vector<int>> dp(row, vector<int>(col));
    
        for(int i=0; i<col; i++)
        {
            dp[0][i]=i;
        }

        for(int i=0; i<row; i++)
        {
            dp[i][0]=i;
        }

        for(int i=1;i<row; i++)
        {
            for(int j=1; j<col; j++)
            {
                if (word1[j-1]==word2[i-1])
                {
                    dp[i][j]=dp[i-1][j-1];
                }
                else
                {
                    dp[i][j] = 1 + min({  dp[i-1][j-1]
                                        , dp[i-1][j]/*插入一個字元後來到這*/
                                        , dp[i][j-1]});/*刪除一個字元後來到這*/  
                }
            }
        }
        return dp[row-1][col-1];
    }
};
class Solution1 {
public:
    //top down  
    vector<vector<int>> memo;
    int minDistance(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        // 初始化 memo 為 -1，表示尚未計算過
        memo = vector<vector<int>>(m + 1, vector<int>(n + 1, -1));
        return dfs(word1, word2, m, n);
    }

    int dfs(const string& word1, const string& word2, int i, int j) {
        // base case：word1 空了，只能插入 j 個字
        if (i == 0) return j;

        // base case：word2 空了，只能刪除 i 個字
        if (j == 0) return i;

        // 如果之前計算過，直接回傳
        if (memo[i][j] != -1) return memo[i][j];

        if (word1[i - 1] == word2[j - 1]) {
            // 最後一個字相同，不需要操作
            memo[i][j] = dfs(word1, word2, i - 1, j - 1);
        } else {
            // 三種操作都試看看，取最小的
            memo[i][j] = 1 + min({
                dfs(word1, word2, i - 1, j - 1), // 替換
                dfs(word1, word2, i, j - 1),     // 插入
                dfs(word1, word2, i - 1, j)      // 刪除
            });
        }

        return memo[i][j];
    }
};