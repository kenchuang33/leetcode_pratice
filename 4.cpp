//O(m+n)
//4. Median of Two Sorted Arrays
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        
        int f=0;
        int s=0;
        int l=nums1.size()+nums2.size();

        int pre_mid=0;
        int cur_mid=0;

        while( (f+s) <= (l/2) )
        {   
            if(f >= nums1.size())
            {
                pre_mid=cur_mid;
                cur_mid=nums2[s];
                s++;
            }
            else if(s>=nums2.size())
            {
                pre_mid=cur_mid;
                cur_mid=nums1[f];
                f++;
            }
            else if(nums1[f] > nums2[s])
            {
                pre_mid=cur_mid;
                cur_mid=nums2[s];
                s++;
            }
            else
            {
                pre_mid=cur_mid;
                cur_mid=nums1[f];
                f++;
            }
        }

        if (l%2==0)
        {
            return double (pre_mid+cur_mid)/2;
        }
        else  return cur_mid;

    }
};

int main() {
    Solution sol;
    vector<int> a1 = {1, 3};
    vector<int> a2 = {2};
    cout << sol.findMedianSortedArrays(a1, a2) << endl; // 輸出 2

    vector<int> b1 = {1, 2};
    vector<int> b2 = {3, 4};
    cout << sol.findMedianSortedArrays(b1, b2) << endl; // 輸出 2.5

    vector<int> c1 = {};
    vector<int> c2 = {1};
    cout << sol.findMedianSortedArrays(c1, c2) << endl; // 輸出 1

    vector<int> d1 = {0, 0};
    vector<int> d2 = {0, 0};
    cout << sol.findMedianSortedArrays(d1, d2) << endl; // 輸出 0

    vector<int> e1 = {};
    vector<int> e2 = {2, 3};
    cout << sol.findMedianSortedArrays(e1, e2) << endl; // 輸出 2.5
}