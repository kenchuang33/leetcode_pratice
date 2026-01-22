// Missing Number
#include <vector>

using namespace std;

class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int n=nums.size();
        int sum=n*(n+1)/2;

        for(auto n: nums)
        {
            sum-=n;
        }

        return sum;

    }
};