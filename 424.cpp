// Longest Repeating Character Replacement

#include <unordered_map>
#include <string>
using namespace std;
// 解題思路: sliding window
// 窗口長度為 r - l + 1。
// 出現次數最多的字符次數 假設為 maxFreq。
// 需要被替換的字符數 就等於：(r - l + 1) - maxFreq。
class Solution {
public:
    int characterReplacement(string s, int k) {
        int l=0;
        int ans=0;
        int freq_char=0;
        unordered_map<char, int> mp;
        
    
        for(int r=0; r<s.size(); r++)
        {
            mp[s[r]]++;

            freq_char=max(freq_char, mp[s[r]]);

            while(( (r-l+1) - freq_char ) > k )
            {
                mp[s[l]]--;
                l++;
            }
            ans =max(ans,r-l+1);

        }

        return ans;
    }
};
// 為什麼不需要重新計算 maxFreq？
// 因為當窗口大小減去 freq_char 超過 k 時，說明窗口內的字符已經不符合條件了。
// 在這種情況下，我們通過收縮窗口左側來嘗試恢復條件。
// 即使 freq_char 沒有更新，它仍然代表窗口內出現頻率最高的字符數量。
// 當我們收縮窗口時，雖然 freq_char 可能不再是窗口內的最高頻率，但這並不影響我們判斷當前窗口是否符合條件。
// 這是因為我們只關心窗口大小與 freq_char 的差值是否超過 k。
// 當窗口符合條件時，我們更新答案 ans。
