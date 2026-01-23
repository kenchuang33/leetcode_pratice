// Contains Duplicate
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        // unordered_map<int, int> rc;

        // for( auto n:nums)
        // {
        //     rc[n]+=1;
        //     if(rc[n]>1) return true;
        // }
        // return false;

        if(nums.size()==1) return false;

        sort(nums.begin(), nums.end());
        
        for(int i=1; i<nums.size(); i++)
        {
            if(nums[i]==nums[i-1]) return true;
        }
        return false;
    }
};