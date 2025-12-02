// Valid Palindrome
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;

        while(l<=r)
        {
            while( (s[l]<'0'|| s[l]>'z'|| (s[l]<'a'&& s[l]>'Z') || (s[l]<'A'&& s[l]>'9')) && l<s.size())
            {
                l++;
            }

            while( (s[r]<'0'|| s[r]>'z'|| (s[r]<'a'&& s[r]>'Z') || (s[r]<'A'&& s[r]>'9')) && r>0 )
            {
                r--;
            }
           
            if(tolower(s[l])==tolower(s[r]))
            {
                l++;
                r--;
            }
            else break;
    
        }

        return l>r ? true:false;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int l=0;
        int r=s.size()-1;
        while (l <= r) 
        {
            while (l < r && !isValid(s[l])) l++;
            while (l < r && !isValid(s[r])) r--;

            if (tolower(s[l]) != tolower(s[r])) return false;

            l++;
            r--;
        }
        return true;
    }

    bool isValid(char c) 
    {
        return  (c >= 'a' && c <= 'z') || 
                (c >= 'A' && c <= 'Z') || 
                (c >= '0' && c <= '9');
    }

};