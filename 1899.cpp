// Merge Triplets to Form Target Triplet
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> temp={1,1,1};
        bool safe;

        for(auto& dir:triplets)
        {
            safe=true;
            for(int i=0; i<3; i++)
            {
                if(dir[i]>target[i]) safe=false;
            }
            if(safe)
            {
                for(int i=0; i<3; i++)
                {
                    temp[i]=max(temp[i],dir[i]);
                }
            }

            if(temp==target) return true;

        }

        return false;
    }
};

class Solution1 {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        // 分別記錄 target 的三個位置是否已經被滿足
        bool pos1 = false, pos2 = false, pos3 = false;

        for (const auto& t : triplets) {
            // 只要其中一個維度大於 target，這個 triplet 就絕對不能選
            if (t[0] > target[0] || t[1] > target[1] || t[2] > target[2]) {
                continue;
            }

            // 如果它是安全的，檢查它是否能幫我們達成某個維度的目標
            if (t[0] == target[0]) pos1 = true;
            if (t[1] == target[1]) pos2 = true;
            if (t[2] == target[2]) pos3 = true;

            // 如果三者都達標，可以提早結束
            if (pos1 && pos2 && pos3) return true;
        }

        return false;
    }
};