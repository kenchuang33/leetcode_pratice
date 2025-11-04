//Reverse Integer
#include <climits>
#include <iostream>
using namespace std;
class Solution {
public:
    int reverse(int x) {
        int answer=0;
        int lead;
        
        while(x!=0)
        {
            lead=x%10;
            x=x/10;
            if (answer > INT_MAX/10 || (answer == INT_MAX/10 && lead > 7)) return 0;
            if (answer < INT_MIN/10 || (answer == INT_MIN/10 && lead < -8)) return 0;
            answer=answer*10+lead;
        }

        return answer;
    }
};
 
int main() {
    Solution s;

    // 一般情況
    cout << "reverse(123) = " << s.reverse(123) << endl;         // 321
    cout << "reverse(-123) = " << s.reverse(-123) << endl;       // -321
    cout << "reverse(120) = " << s.reverse(120) << endl;         // 21
    cout << "reverse(0) = " << s.reverse(0) << endl;             // 0

    // 溢位情況
    cout << "reverse(1534236469) = " << s.reverse(1534236469) << endl;   // 0 (overflow)
    cout << "reverse(-1563847412) = " << s.reverse(-1563847412) << endl; // 0 (overflow)

    // 貼邊測試（靠近邊界）
    cout << "reverse(2147483412) = " << s.reverse(2147483412) << endl;   // 2143847412
    cout << "reverse(-2147483412) = " << s.reverse(-2147483412) << endl; // -2143847412

    // 單一位數
    cout << "reverse(5) = " << s.reverse(5) << endl;             // 5
    cout << "reverse(-9) = " << s.reverse(-9) << endl;           // -9

    // 特殊 case
    cout << "reverse(1000000003) = " << s.reverse(1000000003) << endl; // 0 (會爆)
    cout << "reverse(-2147483648) = " << s.reverse(-2147483648) << endl; // 0 (INT_MIN 溢位)

    return 0;
}