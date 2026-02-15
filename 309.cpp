// Best Time to Buy and Sell Stock with Cooldown
#include <vector>

using namespace std;
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if (prices.empty()) return 0;

        // 初始狀態定義：
        // hold: 手上有股票的最大利潤 (第一天買入，利潤為負的股價)
        // rest: 手上沒股票，且今天「可以」買入的最大利潤 (自由身)
        // sell: 手上沒股票，且今天「剛賣掉」的最大利潤 (處於冷卻期)
        int hold = -prices[0];
        int rest = 0;
        int sell = 0;

        for(int i = 1; i < prices.size(); i++) {
            // 備份昨天的狀態，因為今天的更新會依賴昨天的舊值
            int prev_hold = hold;
            int prev_rest = rest;
            int prev_sell = sell;

            // 狀態轉移：
            
            // 1. 今天結束後「持有股票」：
            //    可能是昨天就拿著 (prev_hold)，或是昨天是自由身今天剛買 (prev_rest - prices[i])
            hold = max(prev_hold, prev_rest - prices[i]);

            // 2. 今天結束後「可以買入（觀望中）」：
            //    可能是昨天就在觀望 (prev_rest)，或是昨天剛賣掉今天解禁了 (prev_sell)
            rest = max(prev_rest, prev_sell);

            // 3. 今天結束後「剛賣掉股票」：
            //    唯一來源是昨天手上有股票，今天把它賣了 (prev_hold + prices[i])
            sell = prev_hold + prices[i];
        }

        // 最後一天手上不應該留股票，利潤最大值一定在「剛賣掉」或「觀望中」產生
        return max(sell, rest);
    }
};