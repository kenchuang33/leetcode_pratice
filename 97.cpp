// Interleaving String
#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
// 2D
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();//col
        int n2=s2.size();//row
        int n3=s3.size();

        if(n3!=(n1+n2)) return false;

       vector<bool> dp(n1+1, false);
      
        dp[0]=true;

        for(int i=1; i<=n1; i++)
        {
            // s1
            dp[i]=dp[i-1] && s3[i-1]==s1[i-1];
        }
        
        for(int i=1;i<=n2; i++)
        {
            dp[0]= dp[0] && (s3[i-1]==s2[i-1]);
            for(int j=1; j<=n1; j++)
            {
                bool try1= ((s3[i+j-1]==s1[j-1]) && dp[j-1]);
                bool try2= ((s3[i+j-1]==s2[i-1]) && dp[j]);
                dp[j]= try1 || try2;
            }
        }
        return dp[n1];
    }
};


class Solution1 {
public:
// 1D
    bool isInterleave(string s1, string s2, string s3) {
        int n1=s1.size();//col
        int n2=s2.size();//row
        int n3=s3.size();

        if(n3!=(n1+n2)) return false;

        vector<vector<bool>> dp( n2+1, vector<bool>( n1+1, false));
      
        dp[0][0]=true;

        for(int i=1; i<=n1; i++)
        {
            // s1
            dp[0][i]=dp[0][i-1] && s3[i-1]==s1[i-1];
        }

        for(int i=1; i<=n2; i++)
        {
            // s2
            dp[i][0]=dp[i-1][0] && s3[i-1]==s2[i-1];
        }

        for(int i=1;i<=n2; i++)
        {
            for(int j=1; j<=n1; j++)
            {
                // bool try1=false;
                // bool try2=false;

                // if(s3[i+j-1]==s1[j-1] && dp[i][j-1]) try1=true;
                // if(s3[i+j-1]==s2[i-1] && dp[i-1][j]) try2=true;
                bool try1= ((s3[i+j-1]==s1[j-1]) && dp[i][j-1]);
                bool try2= ((s3[i+j-1]==s2[i-1]) && dp[i-1][j]);
                dp[i][j]= try1 || try2;
            }
        }


        

        return dp[n2][n1];


    }
};
