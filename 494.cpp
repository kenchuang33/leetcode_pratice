// Target Sum
#include <vector>
#include <unordered_map>
#include <string>
using namespace std;

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // convert to subset sum problem
        // 2D DP
        int sum=0;
        for(auto n:nums)
        {
            sum+=n;
        }
        
        int s;
        if((sum+target) % 2==1 || abs(target)>sum  ) return 0;
        else s=(sum+target)/2;

        int n =nums.size();
        vector<vector<int>> dp(n+1,vector<int> (s+1,0));

        dp[0][0]=1;

        for(int i =1; i<n+1; i++)
        {
            for(int j=0; j<s+1; j++)
            {
                
                dp[i][j]=dp[i-1][j]; 
                //不用

                if(j>=nums[i-1]) 
                {
                    dp[i][j]+=dp[i-1][j-nums[i-1]];
                }
                // 用
            }
        }

        return dp[n][s];
    }
};

class Solution1 {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        // 1D DP
        int sum=0;
        for(auto n:nums)
        {
            sum+=n;
        }
        
        int s;
        if((sum+target) % 2==1 || abs(target)>sum  ) return 0;
        else s=(sum+target)/2;

        int n =nums.size();
        vector<int> dp(s+1,0);

        dp[0]=1;

        for(int i =0; i<n; i++)
        {
            for(int j=s; j>=0; j--)
            {
                if(j>=nums[i]) 
                {
                    dp[j]+=dp[j-nums[i]];
                }
            }
        }

        return dp[s];
    }
};

class Solution2 {
public:
// Backtracking + Memoization
    unordered_map<string, int> mp;
    int backtrack(vector<int>& nums, int index, int cur_sum,int target)
    {
        if(index==nums.size())
        {
            if(cur_sum==target) return 1;
            else return 0;
        }
        
        string temp=to_string(index)+'_'+to_string(cur_sum);
        if(mp.count(temp)) return mp[temp];
        
        int sum=(backtrack(nums, index+1, cur_sum+nums[index], target)+
                 backtrack(nums, index+1, cur_sum-nums[index], target));

        mp[temp]=sum;
        
        return sum;

    }
    int findTargetSumWays(vector<int>& nums, int target) {
       return backtrack(nums, 0, 0, target);
    }

};