// Min Cost Climbing Stairs
#include <vector>
using namespace std;

class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {

        int n=cost.size();
        // 因為可以從第0或第1階開始 所以前兩階的cost就是本身 
        int prev1=cost[1];
        int prev2=cost[0];

        // 從第2階開始算到最後一階
        for(int i=2; i<n; i++)
        {
            int cur=cost[i]+min(prev1,prev2);
            prev2=prev1;
            prev1=cur;
        }
        
        // 看是從倒數第一階或倒數第二階踏上去比較省
        return min(prev1,prev2);

    }
};

