// Plus One
#include <iostream>
#include <vector>
using namespace std;
class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n =digits.size();
       
        digits[n-1]+=1;
        int carry=0;

        for(int i =n-1; i>=0; i--)
        {
            digits[i]+=carry;
            carry=digits[i]/10;
            digits[i]%=10;
        }

        if (digits[0]==0)//carry==1
        {
            digits.insert(digits.begin(),1);
        }
        
        
        return digits;
    
    }
};
int main() {
    Solution sol;
    
    vector<vector<int>> testcases = {
        {1, 2, 3},      // ➜ [1, 2, 4]
        {9},            // ➜ [1, 0]
        {0},            // ➜ [1]
        {9, 9},         // ➜ [1, 0, 0]
        {2, 9},         // ➜ [3, 0]
        {8, 9, 9, 9},   // ➜ [9, 0, 0, 0]
        {9, 0, 9},      // ➜ [9, 1, 0]
        {1, 9, 9},      // ➜ [2, 0, 0]
        {1, 0, 0},      // ➜ [1, 0, 1]
    };

    for (auto& digits : testcases) {
        vector<int> result = sol.plusOne(digits);
        cout << "[";
        for (int i = 0; i < result.size(); i++) {
            cout << result[i];
            if (i != result.size() - 1) cout << ", ";
        }
        cout << "]" << endl;
    }

    return 0;
}
