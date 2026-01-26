// House Robber II
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        if(n==1) return nums[0];
        if (n==2) return max(nums[0],nums[1]);
        
        vector<int> result1(n-1,0);
        vector<int> result2(n-1,0);
        
        // rob first house
        int p1=0;
        int p2=0;
        for(int i=0; i<n-1; i++)
        {
            result1[i]=max(p1,nums[i]+p2);
            p2=p1;
            p1=result1[i];
        }
        
        // not rob first house
        p1=0;
        p2=0;

        for(int i=1; i<n; i++)
        {
            result2[i-1]=max(p1,nums[i]+p2);
            p2=p1;
            p1=result2[i-1];
        }
        

        return max(result1[n-2],result2[n-2]);
    }
};