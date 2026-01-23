// K-th Symbol in Grammar
#include <iostream>

using namespace std;

class Solution {
public:
    int kthGrammar(int n, int k) {
        
        if(n==1) return 0;

        long long mid =pow(2, n-2);

        if(k<=mid)
        {
            return kthGrammar(n-1, k);
        }
        else
        {
            return !kthGrammar(n-1, k-mid);
        }
    }
};

class Solution1 {
public:
    int kthGrammar(int n, int k) {
        
        int res=0;

        while(n>1)
        {
            long long mid =pow(2, n-2);
            if (k>mid)
            {
                res=!res;
                k-=mid;
            }

            n--;
        }
        return res;
    }
};
