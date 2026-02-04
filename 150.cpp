// Evaluate Reverse Polish Notation
#include <vector>
#include <string>
#include <stack>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        for(auto& s: tokens)
        {
            if(s=="+")
            {
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();

                st.push(num1+num2);
            }
            else if(s=="-")
            {
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();

                st.push(num1-num2);
            }
            else if(s=="*")
            {
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();

                st.push(num1*num2);
            }
            else if(s=="/")
            {
                int num2=st.top();
                st.pop();
                int num1=st.top();
                st.pop();

                st.push(num1/num2);
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};