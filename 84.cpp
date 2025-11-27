// Largest Rectangle in Histogram
#include <iostream>
#include <vector>
#include <stack>
using namespace std;
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        stack<pair<int, int>> rc;
        int maxsize=0;

        for(int i=0; i<heights.size(); i++)
        {
            int start_index=i;
            while(!rc.empty() && heights[i] < rc.top().second)
            {
                int top_index=rc.top().first;
                int top_val=rc.top().second;

                int size=top_val*(i-top_index);
                maxsize=max(maxsize,size);

                start_index=top_index;

                rc.pop();
            }
            rc.push({start_index,heights[i]});
        }

        while(!rc.empty())
        {
            int top_index=rc.top().first;
            int top_val=rc.top().second;

            int size=top_val*(heights.size()-top_index);
            maxsize=max(maxsize,size);

             rc.pop();
            
        }

        return maxsize;
    }
};

class Solution1 {
public:
// 在最後柱子後面加上一個高度為0的柱子，可以使得剩下的stack的都清空
    int largestRectangleArea(vector<int>& heights) {
        stack<pair<int, int>> st;
        int maxArea = 0;

        heights.push_back(0); // 加上哨兵柱子，強迫最後把 stack 清空

        for (int i = 0; i < heights.size(); i++) {
            int startIndex = i;

            while (!st.empty() && heights[i] < st.top().second) {
                int index = st.top().first;
                int height = st.top().second;
                st.pop();

                int area = height * (i - index);
                maxArea = max(maxArea, area);
                startIndex = index;  // 繼續向左擴展
            }

            st.emplace(startIndex, heights[i]); // 用 emplace 更高效
        }

        return maxArea;
    }
};
