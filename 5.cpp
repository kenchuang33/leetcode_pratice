//Longest Palindromic Substring
#include <vector>
#include <iostream>
#include <string> 
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {

        string longest="";
        for(int i=0; i<s.size(); i++)
        {

        string odd = cal(s,i,i);
        string even= cal(s,i,i+1);

        int odd_size=odd.size();
        int even_size=even.size();

        if(odd_size > longest.size())
        {
            longest=odd;
        }

        if(even_size>longest.size())
        {
            longest=even;
        }

        }
        return longest;
    }

    string cal(string &s, int l, int r)
    {
        while(l>=0 && r < s.size() && s[l]==s[r])
        {
            l--;
            r++;
        }
        return s.substr(l+1,r-l-1);
    }
};

int main() {
    Solution sol;

    
    vector<string> testCases = {
        "babad",
        "cbbd",
        "a",
        "ac",
        "racecar",
        "abba",
        "abcba",
        "abcdedcba",
        "xyz"
    };

    for (const string& s : testCases) {
        string result = sol.longestPalindrome(s);
        cout << "Input: \"" << s << "\" → Output: \"" << result << "\"" << endl;
    }

    return 0;
}