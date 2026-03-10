// Longest Increasing Subsequence
#include <vector>
using namespace std;

class Solution {
public:
// O(n^2) DP
    int lengthOfLIS(vector<int>& nums) {
        int n =nums.size();
        vector<int> dp(n,1);

        if (n==1) return 1;
        int ans=1;

        for(int i=1; i<n; i++)
        {
            for(int j=0; j<i; j++)
            {
                if(nums[i]>nums[j]) 
                {
                    dp[i]=max(dp[j]+1,dp[i]);        
                    ans=max(dp[i],ans);
                }
            }
        }

        return ans;
    }
};


