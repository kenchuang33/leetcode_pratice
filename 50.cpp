// Pow(x, n)
#include <iostream>
#include <cmath>
using namespace std;

class Solution {
public:
    double myPow(double x, int n) {
        long long pow = n; // 為了處理 INT_MIN
        if (pow < 0) {
            x = 1 / x;
            pow = -pow;
        }

        double ans = 1.0;
        double base = x;

        // 👉 補上 while 迴圈邏輯
        while (pow > 0)
        {
            if (pow % 2 == 1) ans *= base; // 如果當前位元是1
            

            base *= base; // base 往上變一倍次方
            pow /= 2;       // 處理下一位（等於往右位移）
        }


        return ans;
    }
};

int main() {
    Solution sol;

    cout << "Test 1: " << sol.myPow(2, 10) << " (expected: 1024)" << endl;
    cout << "Test 2: " << sol.myPow(2, -2) << " (expected: 0.25)" << endl;
    cout << "Test 3: " << sol.myPow(3, 0) << " (expected: 1)" << endl;
    cout << "Test 4: " << sol.myPow(0, 5) << " (expected: 0)" << endl;
    cout << "Test 5: " << sol.myPow(5, 1) << " (expected: 5)" << endl;
    cout << "Test 6: " << sol.myPow(2, 31) << " (expected: large number)" << endl;
    cout << "Test 7: " << sol.myPow(2, -2147483648) << " (expected: ~0)" << endl;
    cout << "Test 8: " << sol.myPow(0.00001, 2147483647) << " (expected: ~0)" << endl;

    return 0;
}

// 1011=11
// 0101=5
// 0010=2
// 0001=1