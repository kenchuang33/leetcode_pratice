// Reaching Points
#include <iostream>

using namespace std;
class Solution {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while(tx>=sx && ty>=sy)
        {
            if (tx==sx && ty==sy) return true;

            if(tx>=ty && ty!=0)
            {
                if (ty>sy) tx=tx%ty;
                else if (ty==sy) return (tx-sx)%ty==0;
            } 
            else if (tx<ty && tx!=0) 
            {
                if(tx>sx) ty=ty%tx;
                else if (sx==tx) return (ty-sy)%tx==0;
            }
        }
        return false;
    }
};

class Solution1 {
public:
    bool reachingPoints(int sx, int sy, int tx, int ty) {
        while (tx > sx && ty > sy) {
            if (tx > ty) {
                tx %= ty;
            } else {
                ty %= tx;
            }
        }

        if (tx == sx && ty >= sy && (ty - sy) % sx == 0) return true;
        if (ty == sy && tx >= sx && (tx - sx) % sy == 0) return true;

        return false;
    }
};
