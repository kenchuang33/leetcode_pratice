// Climbing Stairs
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n,0);
        if(n==1) return 1;
        dp[0]=1;
        dp[1]=2;

        for(int i=2; i<n; i++)
        {
           dp[i]=dp[i-1]+dp[i-2]; 
        }

        return dp[n-1];
    }
};
class Solution1 {
public:
    // 空間O(1)
    int climbStairs(int n) {
        
        if(n==1) return 1;
        if(n==2) return 2;
        int a=1;
        int b=2;
        int c;
        for(int i=2; i<n; i++)
        {
            c=a+b;           
            a=b;
            b=c;
        }

        return c;
    }
};
int main() {
    Solution sol;
    Solution1 sol1;

    vector<int> tests = {1, 2, 3, 4, 5, 10, 20};

    for (int n : tests) {
        cout << "n = " << n << endl;
        cout << "dp version  : " << sol.climbStairs(n) << endl;
        cout << "O(1) version: " << sol1.climbStairs(n) << endl;
        cout << "-------------------------" << endl;
    }

    return 0;
}