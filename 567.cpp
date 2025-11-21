// Permutation in String
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int window=s1.size();
        

        unordered_map<char,int> rc1;
        unordered_map<char,int> rc2;

        for(auto i :s1)
        {
            rc1[i]++;
        }

        int l=0;
        
        for(int r=0; r<s2.size(); r++)
        {
            char c=s2[r];
            rc2[c]++;

            if((r-l+1)==window)
            {   
                if(rc1==rc2) return true;
                char leftchar=s2[l];
                rc2[leftchar]--;
                if (rc2[leftchar] == 0) 
                {
                    rc2.erase(leftchar); // 清掉為 0 的字元
                }
                l++;
            }
            
        }
        return false;
        
    }
};
int main() {
    Solution sol;

    vector<pair<string, string>> tests = {
        {"ab", "eidbaooo"},      // true
        {"ab", "eidboaoo"},      // false
        {"adc", "dcda"},         // true ("cda" is a permutation)
        {"hello", "ooolleoooleh"}, // false
        {"a", "a"},              // true
        {"abc", "ccccbbbbaaaa"}, // false
        {"abcd", "eidbacdooo"},  // true ("bacd" is a permutation)
        {"xyz", "afdgzyxksldfm"}, // true ("zyx")
        {"aabb", "abab"},        // true ("abab" is a permutation of "aabb")
    };

    for (auto &[s1, s2] : tests) {
        cout << "s1 = \"" << s1 << "\", s2 = \"" << s2 << "\" -> "
             << (sol.checkInclusion(s1, s2) ? "true" : "false") << endl;
    }

    return 0;
}