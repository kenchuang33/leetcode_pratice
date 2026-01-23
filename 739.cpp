// Daily Temperatures
#include <iostream>
#include <vector>
#include <queue>
#include <stack>

using namespace std;
class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>> > pq;

        vector<int> ans=temperatures;

        for(int i=0; i<temperatures.size(); i++)
        {
            while(!pq.empty() && (pq.top().first<temperatures[i]))
            {
                auto [ h,index ]=pq.top();
                pq.pop();
                ans[index]=i-index;
            }
            pq.push({temperatures[i], i});
        }

        while(!pq.empty())
        {
            auto [ h,index ]=pq.top();
            pq.pop();
            ans[index]=0;
        }

        return ans;

    }
};

class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        stack<int> st;
        int n =temperatures.size();
        vector<int> ans(n, 0);

        for(int i=0; i<n; i++)
        {
            while(!st.empty() && (temperatures[st.top()] < temperatures[i]))
            {
                int index=st.top();
                st.pop();
                ans[index]=i-index;
            }
            st.push(i);
        }
    
        return ans;

    }
};