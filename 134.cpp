// Gas Station
#include <vector>
using namespace std;
class Solution {
public:
// O(n2)
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int cur_gas=0;
        int n=gas.size();
        int res=-1;

        for(int i=0; i<n; i++)
        {
            if(gas[i]>=cost[i]) 
            {
                cur_gas=gas[i]-cost[i];
                for(int j=1; j<=n; j++)
                {
                    cur_gas=cur_gas+gas[(i+j)%n]-cost[(i+j)%n];
                    if (cur_gas < 0)
                    {
                        i=i+j;
                        break;
                    } 
                }
                if(cur_gas>=0) res=i;

            }
            
        }

        return res;
    }
};

class Solution1 {
public:
// O(N) greedy way
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas=0;
        int n=gas.size();
        int cur_gas=0;
        int res_index=0;

        for(int i=0; i<n; i++)
        {
            int diff=gas[i]-cost[i];
            total_gas+=total_gas+diff;
            cur_gas+=diff;

            if(cur_gas<0) 
            {
                cur_gas=0;
                res_index=i+1;
            }
            
        }

        return total_gas>=0? res_index:-1;
    }
};





