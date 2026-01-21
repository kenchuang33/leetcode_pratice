//Partition Equal Subset Sum
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;


class Solution {
public:
    // set based solution
    bool canPartition0(vector<int>& nums) {
        int sum=0;
        int target=0;
        
        for(auto n :nums)
        {
            sum+=n;
        }

        if (sum%2==1) 
        {
            return false;
        }
        else target=sum/2;
        
        unordered_set<int> dp;
        unordered_set<int> dp_temp;
        dp.insert(0);

        for(auto& n:nums)
        {
            dp_temp=dp;
            for(auto& cur:dp_temp)
            {
                if((n+cur) == target) return true;
                else if((n+cur)> target) continue;
                else dp.insert(n+cur);
            }
        }
        return false;
    }

    // 2D DP
    bool canPartition(vector<int>& nums) {
        int sum=0;
        int target=0;
        
        for(auto n :nums)
        {
            sum+=n;
        }

        if (sum%2==1) 
        {
            return false;
        }
        else target=sum/2;
        
        int n=nums.size();
        vector<vector<bool>> dp(n+1, vector<bool>(target+1,false));
        
        for(int i=0; i<=n; i++)
        {
            dp[i][0]=true;
        }

        for(int i=1; i<=n; i++)
        {
            for(int j=1; j<=target; j++)
            {
                if(j>=nums[i-1])
                {
                    dp[i][j] = dp[i-1][j] || dp[i-1][j-nums[i-1]];
                }
                else
                {
                    dp[i][j] = dp[i-1][j];
                }
            }
        }
        return dp[n][target];
    }

    // 1D DP
    bool canPartition1(vector<int>& nums) {
        int sum=0;
        int target=0;
        
        for(auto n :nums)
        {
            sum+=n;
        }

        if (sum%2==1) 
        {
            return false;
        }
        else target=sum/2;
        
        vector<bool> dp(target+1,false);
        dp[0]=true;

        for(auto& n:nums)
        {
            // 因為會用到前一個狀態的值，所以要從後往前更新
            for(int j=target; j>=n; j--)
            {
                dp[j] = dp[j] || dp[j-n];
            }
        }
        return dp[target];
    }



};