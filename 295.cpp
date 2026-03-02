//  Find Median from Data Stream

#include <vector>
#include <queue>
using namespace std;
/**
 * Your MedianFinder object will be instantiated and called as such:
 * MedianFinder* obj = new MedianFinder();
 * obj->addNum(num);
 * double param_2 = obj->findMedian();
 */

class MedianFinder {
    vector<int> nums;
public:
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        int left=0;
        int right=nums.size()-1;
        int target=nums.size();

        while(left<=right)
        {
            int mid=left+(right-left)/2;

            if(nums[mid]>num)
            {
                target=mid;
                right=mid-1;
                
            }
            else
            {
                left=mid+1;
            }
        }

        nums.insert(nums.begin()+target, num);


    }
    
    double findMedian() {
        int n = nums.size();
        return n%2? (double)nums[n/2] : (double) (nums[n/2]+nums[n/2-1])/2;
    }
};

class MedianFinder_heap {
    // 維護兩個 heap，small 是 maxheap，big 是 minheap
    priority_queue<int> small; //maxheap
    priority_queue<int, vector<int>, greater<int> > big; //minheap
public:
    MedianFinder_heap() {
        
    }
    
    void addNum(int num) {
        
        small.push(num);

        big.push(small.top());
        small.pop();

        if(small.size() < big.size())
        {
            small.push(big.top());
            big.pop();
        }

    }
    
    double findMedian() {
        if (small.size()==big.size()) return (double) (small.top()+big.top())/2;
        return (double) small.top();
    }
};

/* Follow up:

1.If all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?
// using counting 

*/
class MedianFinder_followup1 {
    vector<int> counts; // 用來存 0-100 每個數字出現的次數
    int totalCount;     // 紀錄目前總共有多少個數字

public:
    MedianFinder_followup1() : counts(101, 0), totalCount(0) {
    }

    void addNum(int num) {
        if (num >= 0 && num <= 100) {
            counts[num]++;
            totalCount++;
        }
    }
    
    double findMedian() {
        if (totalCount == 0) return 0.0;

        // 我們需要找到第 k 個數
        // 如果總數是奇數：找第 (totalCount / 2) + 1 個數
        // 如果總數是偶數：找第 (totalCount / 2) 與 (totalCount / 2) + 1 個數的平均
        
        int mid1 = (totalCount + 1) / 2;
        int mid2 = (totalCount / 2) + 1;
        
        int countSum = 0;
        int val1 = -1, val2 = -1;

        // 遍歷計數陣列 (O(101) -> O(1))
        for (int i = 0; i <= 100; ++i) {
            countSum += counts[i];
            
            // 找到第 mid1 個數
            if (val1 == -1 && countSum >= mid1) {
                val1 = i;
            }
            // 找到第 mid2 個數
            if (val2 == -1 && countSum >= mid2) {
                val2 = i;
                break; // 兩個都找到了，可以直接跳出
            }
        }

        if (totalCount % 2 != 0) {
            return (double)val1;
        } else {
            return (val1 + val2) / 2.0;
        }
    }
};




/* Follow up:

2.If 99% of all integer numbers from the stream are in the range [0, 100], how would you optimize your solution?

*/
class MedianFinder_followup2 {
    int counts[101] = {0}; // 處理 99% 的數據
    vector<int> less;      // 處理 < 0
    vector<int> greater;   // 處理 > 100
    int totalCount = 0;

public:
    void addNum(int num) {
        if (num < 0) {
            // 保持 less 有序 (或用 heap)
            auto it = lower_bound(less.begin(), less.end(), num);
            less.insert(it, num);
        } else if (num > 100) {
            // 保持 greater 有序
            auto it = lower_bound(greater.begin(), greater.end(), num);
            greater.insert(it, num);
        } else {
            counts[num]++;
        }
        totalCount++;
    }

    double findMedian() {
        // 我們需要找到第 k 個數，邏輯跟之前一樣
        int mid1 = (totalCount + 1) / 2;
        int mid2 = (totalCount / 2) + 1;
        
        return (getKth(mid1) + getKth(mid2)) / 2.0;
    }

private:
    int getKth(int k) {
        // 1. 先看是不是在 less 桶子裡
        if (k <= less.size()) {
            return less[k - 1];
        }
        
        // 2. 扣除 less 的數量，看是不是在 counts[101] 裡
        int currentK = k - less.size();
        for (int i = 0; i <= 100; ++i) {
            if (currentK <= counts[i]) {
                return i;
            }
            currentK -= counts[i];
        }
        
        // 3. 如果還沒找到，就在 greater 桶子裡
        return greater[currentK - 1];
    }
};



