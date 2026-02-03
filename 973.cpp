// K Closest Points to Origin

#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        sort(points.begin(), points.end(), [](const vector<int>& a, const vector<int>& b){
            return (a[0]*a[0]+a[1]*a[1])<(b[0]*b[0]+b[1]*b[1]);
         });

         vector<vector<int>> result={};
         for(int i=0;i<k; i++)
         {
            result.push_back(points[i]);
         }

         return result;
    }
};
class Solution1 {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        // 修正點 1: greater 裡的型別要跟存進去的東西一致，都是 vector<int>
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;

        for(auto& p : points)
        {
            int dist = p[0]*p[0] + p[1]*p[1];
            // 修正點 2: 直接 push 一個初始化好的 vector
            pq.push({dist, p[0], p[1]});
        }

        vector<vector<int>> ans;
        for(int i=0; i<k; i++)
        {
            vector<int> cur = pq.top(); 
            pq.pop();
            // 修正點 3: 直接取出座標部分，不需要再開一個迴圈
            ans.push_back({cur[1], cur[2]});
        }

        return ans;
    }
};