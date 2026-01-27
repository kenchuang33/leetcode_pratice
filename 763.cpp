// Partition Labels
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> partitionLabels(string s) {
        unordered_map<char, pair<int, int>> rc;

        for(int i=0; i<s.size(); i++)
        {
            char c=s[i];
            if(rc.count(c))
            {
                rc[c].second=i;
            }
            else rc[c]={i,i};
        }
        vector<int> ans;
        int start=0;
        int end=0;

        for(int i=0;i<s.size();i++)
        {
            char c=s[i];

            end=max(rc[c].second,end);
            
            if (i==end)
            {
                ans.push_back(end-start+1);
                start=i+1;
            }

        }

        return ans;
    }
};