// Decode Ways
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.size()+1,0);
        
        dp[0]=1;
        

        for(int i=0; i<s.size(); i++)
        {
            if( s[i]!='0' )
            {
                dp[i+1]+=dp[i];
            }

            if(i>=1 && (s[i-1]=='1' || (s[i-1]=='2' &&  (s[i]-'0')<7)))
            {
                dp[i+1]+=dp[i-1];
            }

        }
        return dp[s.size()];
    }
};


class Solution1 {
public:
    int numDecodings(string s) {
        int prev_two=1;
        int prev_one=1;
        if(s[0]=='0') return 0;
        

        for(int i=0; i<s.size(); i++)
        {
            
            int target=0;

            if( s[i]!='0')
            {
               target=prev_one;
            }
            if(i>=1 && (s[i-1]=='1' || (s[i-1]=='2' &&  (s[i]-'0')<7)))
            {
               target+=prev_two;
            }
            
            prev_two=prev_one;
            prev_one=target;



        }
        return prev_one;
    }
};
