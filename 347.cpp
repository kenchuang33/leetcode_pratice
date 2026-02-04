// Top K Frequent Elements
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;
class Solution {
public:
// O(n log k)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto n : nums)
        {
            mp[n]++;
        }

        priority_queue<vector<int>> pq;
        for(auto [k,v] : mp)
        {
            pq.push({v,k});
        }

        vector<int> result={};

        for(int i=0; i<k; i++)
        {
            result.push_back(pq.top()[1]);
            pq.pop();
        }

        return result;

    }
};

class Solution {
public:
// O(n)
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        for(auto n : nums) mp[n]++;

        // 1. 修改點：桶子必須是 vector 的 vector，用來裝相同頻率的多個數字
        vector<vector<int>> buckets(nums.size() + 1);
        for(auto [val, freq] : mp) {
            buckets[freq].push_back(val);
        }

        vector<int> result;
        // 2. 從頻率最高的桶子（後方）開始往回找
        for(int i = buckets.size() - 1; i >= 0 && result.size() < k; i--) {
            for(int num : buckets[i]) {
                result.push_back(num);
                if(result.size() == k) break;
            }
        }

        return result;
    }
};