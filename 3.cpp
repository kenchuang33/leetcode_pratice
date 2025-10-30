// 3.Longest Substring Without Repeating Characters
#include <string>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int left = 0;
        int maxLen = 0;
        unordered_map<char, int> rc;

        for (int right = 0; right < (int)s.size(); ++right) {
            char c = s[right];
            rc[c]++;
            while (rc[c] > 1) {
                rc[s[left]]--;
                left++;
            }
            maxLen = max(maxLen, right - left + 1);
        }
        return maxLen;
    }
};

int main() {
    Solution sol;
    cout << sol.lengthOfLongestSubstring("abcabcbb") << endl;  // 3
    cout << sol.lengthOfLongestSubstring("abbbbb") << endl;    // 2
    cout << sol.lengthOfLongestSubstring("pwwkew") << endl;    // 3
    cout << sol.lengthOfLongestSubstring("") << endl;          // 0
    cout << sol.lengthOfLongestSubstring(" ") << endl;         // 1
    cout << sol.lengthOfLongestSubstring("dvdf") << endl;      // 3
    cout << sol.lengthOfLongestSubstring("abba") << endl;      // 2
    cout << sol.lengthOfLongestSubstring("tmmzuxt") << endl;   // 5
}
