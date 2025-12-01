// Best Time to Buy and Sell Stock
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
// greedy way
    int maxProfit(vector<int>& prices) {
        if(prices.size()==0) return 0;
        int min_val=prices[0];
        int max_val=prices[0];
        int max_dif=0;

        for(int i : prices)
        {
            if (i<min_val)
            {
                min_val=i;
                max_val=i;
            }
            else max_val=max(max_val, i);
            max_dif=max(max_dif, max_val-min_val);

        }

        return max_dif;
    }
};

class Solution1 {
public:
// dp
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n==0) return 0;
        
        vector<int> dp(n, 0);
        int minval=prices[0];
        for(int i=1; i<n; i++)
        {
            minval=min(minval,prices[i]);
            dp[i]=max(dp[i-1], prices[i]-minval);
        }

        return dp[n-1];
    }
};