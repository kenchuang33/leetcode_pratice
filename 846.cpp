// Hand of Straights
#include <map>
#include <vector>
using namespace std;

class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(auto& n:hand)
        {
            mp[n]++;
        }

        for(auto& [k,v]:mp)
        {
            while(v>0)
            {
                for(int i=0; i<groupSize; i++)
                {
                    if(!mp.count(k+i) || mp[k+i]==0) return false;
                    else mp[k+i]--;
                }
            }
        }

        return true;
    }
};


class Solution1 {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        map<int,int> mp;
        for(auto& n:hand)
        {
            mp[n]++;
        }

        for (auto it = mp.begin(); it != mp.end(); ++it) {
        int val = it->first;
        int count = it->second;
    
        if (count > 0) {
            // 嘗試從當前這張牌開始，一次消耗掉 count 個順子
            for (int i = 0; i < groupSize; ++i) {
                if (mp[val + i] < count) return false;
                mp[val + i] -= count;
            }   
        }
    }

        return true;
    }
};

