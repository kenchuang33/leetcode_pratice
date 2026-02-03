// Non-overlapping Intervals
#include <vector>
#include <algorithm>
using namespace std;
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        // Sort intervals based on their end time
        // greedy approach
        sort(intervals.begin(), intervals.end(), [](const vector<int>& a ,const vector<int>& b) {
            return a[1]<b[1];
         });

        int count=0;

        int end=intervals[0][1];

        for(int i=1; i<intervals.size(); i++)
        {
            if(intervals[i][0]< end) count++;
            else
            {
                end=intervals[i][1];
            }
        }

        return count;
    }
};