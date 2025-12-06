//  Single Number
#include <vector>
using namespace std;
class Solution {
public:
    // 對於每一個數字已二進位的方式，使用XOR 0^0=0, 0^1=1, 1^0=1, 1^1=0;
    int singleNumber(vector<int>& nums) {
        int res=0;
        for(int& n : nums)
        {
            res=res^n;
        }
        return res;
    }
};