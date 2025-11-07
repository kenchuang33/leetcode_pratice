//Generate Parentheses
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void dfs(string res, int left, int right)
    {
        if (left==0 && right==0)
        {
            ans.push_back(res);
            return;
        }

        if(left>0)
        {
            res.push_back('(');
            dfs(res,left-1,right);
            res.pop_back();
            // dfs(res+'(',left-1,right);
        }
        
        if(right>left)
        {
            res.push_back(')');
            dfs(res,left,right-1);
            res.pop_back();
            // dfs(res+')',left,right+1);
        }
    }
    vector<string> generateParenthesis(int n) {
        ans.clear();
        dfs("",n,n);
        return ans;
    }

};
int main() {
    Solution s;

    vector<int> testcases = {1, 2, 3};
    
    for (int n : testcases) {
        cout << "n = " << n << endl;
        vector<string> result = s.generateParenthesis(n);
        for (const string& str : result) {
            cout << str << " ";
        }
        cout << "\n---\n";
    }

    return 0;
}

    