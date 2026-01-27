// Valid Anagram
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
    class Solution {
    public:
        bool isAnagram(string s, string t) {
            
            string w1=s;
            string w2=t;

            sort(w1.begin(), w1.end());
            sort(w2.begin(), w2.end());

            if(w1.size()!=w2.size()) return false;
            for(int i=0; i<w1.size(); i++)
            {
                if (w1[i]!=w2[i]) return false;
            }

            return true;

        }
    };

    class Solution1 {
    public:
        bool isAnagram(string s, string t) {
            
            unordered_map<char, int> rc;

            for(auto& c:s)
            {
                rc[c]++;
            }

            for(auto& c:t)
            {
                if(!rc.count(c)) return false;
                rc[c]--;
                if (rc[c]==0) rc.erase(c);
            }

            return rc.size()==0? true : false;

        }
    };