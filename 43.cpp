//Multiply Strings
#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
public:
    string multiply(string num1, string num2) {
        int n1=num1.size();
        int n2=num2.size();

        vector<int> res(n1+n2,0); //兩位數*三位數 最多只有2+3的位數

        for(int i=n1-1; i>=0; i--) //從右邊往左邊
        {
            for(int j=n2-1; j>=0; j--)
            {
                int d1=num1[i]-'0';
                int d2=num2[j]-'0';

                int num=d1*d2; 

                int sum = res[i+j+1]+num; //先+起來以最終的一起看，再決定要不要進位，這樣可以解決可能原本的res[i+j+1]就要進位的問題]

                res[i+j+1]=sum%10;
                res[i+j]+=sum/10;
        //      int num=d1*d2;

        //      res[i+j+1]+=num%10;
        //      res[i+j]+=num/10;
            }
        }

        // for(int i=res.size()-1; i>0; i--)
        // {
        //     if(res[i]>=10){
        //         res[i-1]+=res[i]/10;
        //         res[i]=res[i]%10;
        //     }
        // }



        string ans;
        
        for (int num : res) 
        {
            if (!(ans.empty() && num == 0)) // 跳過前導零
                ans += to_string(num);
        }

        return ans.empty() ? "0" : ans;
        
    }
};

int main() {
    Solution s;

    vector<pair<string, string>> testcases = {
        {"2", "3"},             // 6
        {"123", "4"},           // 492
        {"99", "99"},           // 9801
        {"1234", "5678"},       // 7006652
        {"0000123", "0456"},    // 56088
        {"0", "123456"},        // 0
        {"999999", "0"},        // 0
        {"123456789", "987654321"} // 121932631112635269
    };

    for (auto& [num1, num2] : testcases) {
        string result = s.multiply(num1, num2);
        cout << num1 << " * " << num2 << " = " << result << endl;
    }

    return 0;
}