//Coin Change II
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        
        int n=coins.size();
        vector<vector< unsigned long long>> dp(amount+1,vector<unsigned long long>(n+1,0));//要用unsigned long long 不然會overflow

        for(int i=0; i<=n; i++ )
        {
            dp[0][i]=1;//金額為0的時候就都不取，只有一種方法
        }
   
        for(int coin=1; coin<=n; coin++)
        {
            for(int sum=0; sum<=amount; sum++)
            {
                int c_val=coins[coin-1];

                dp[sum][coin]= dp[sum][coin-1];
                
                if(sum>=c_val)//如果可以至少用一次的話
                {
                    dp[sum][coin]+=dp[sum-c_val][coin];
                }
                
            }
        }
        
        
        return (int)dp[amount][n];
    }   
};
class Solution1 {
public:
    int change(int amount, vector<int>& coins) {
        vector<unsigned long long> dp(amount + 1, 0);
        dp[0] = 1;  // 湊出 0 元，只有一種方式：不拿

        for (int coin : coins) {
            for (int a = coin; a <= amount; ++a) {
                dp[a] += dp[a - coin];//看成 我可以在湊出 a - coin 的組合後，再加一枚 coin
            }
        }

        return (int)dp[amount];
    }
};

int main() {
    Solution sol1;
    Solution1 sol2;

    vector<pair<int, vector<int>>> test_amounts = {
        {5, {1,2,5}},
        {3, {2}},
        {10, {10}},
        {0, {1,2,3}},
        {5, {}},
        {100, {1,2,5}},
        {500, {1,2,5,10,20,50,100,200}},
    };

    vector<int> expected = {
        4,
        0,
        1,
        1,
        0,
        541,
        6295434
    };

    for (int i = 0; i < test_amounts.size(); ++i) {
        int amount = test_amounts[i].first;
        vector<int> coins = test_amounts[i].second;

        int res1 = sol1.change(amount, coins);
        int res2 = sol2.change(amount, coins);

        cout << "Test " << i+1 << ": amount = " << amount << ", coins = { ";
        for (int c : coins) cout << c << " ";
        cout << "}\n";

        cout << "  ➤ Solution (2D) : " << res1 << "\n";
        cout << "  ➤ Solution1 (1D): " << res2 << "\n";
        cout << "  ➤ Expected      : " << expected[i] << "\n";

        cout << (res1 == expected[i] && res2 == expected[i] ? "✅ Passed\n\n" : "❌ Failed\n\n");
    }

    return 0;
}

