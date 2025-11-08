/**
 * Definition for singly-linked list.
 */
//Merge k Sorted Lists
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode 
{
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
class Solution {
public:



    struct Compare {
        bool operator()(ListNode* a, ListNode* b) {
            return a->val > b->val; // 小的在上面（min-heap）
        }
    };

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*, vector<ListNode*>, Compare> pq;

        // 1. 初始化：把每個 list 的頭放進 heap
        for (auto node : lists) {
            if (node) pq.push(node);
        }

        ListNode* dummy = new ListNode();
        ListNode* cur = dummy;

        // 2. 合併
        while (!pq.empty()) {
            ListNode* minNode = pq.top();
            pq.pop();

            cur->next = minNode;
            cur = cur->next;

            if (minNode->next) pq.push(minNode->next);
        }

        return dummy->next;
    }
};

// 🔍 輔助函數：建立 linked list
ListNode* buildList(const vector<int>& nums) {
    ListNode* dummy = new ListNode();
    ListNode* cur = dummy;
    for (int n : nums) {
        cur->next = new ListNode(n);
        cur = cur->next;
    }
    return dummy->next;
}

// 🔍 輔助函數：印出 linked list
void printList(ListNode* head) {
    while (head) {
        cout << head->val;
        if (head->next) cout << " -> ";
        head = head->next;
    }
    cout << endl;
}

// ✅ 主程式測試
int main() {
    Solution solution;

    // 建立三個 sorted list
    ListNode* l1 = buildList({1, 4, 5});
    ListNode* l2 = buildList({1, 3, 4});
    ListNode* l3 = buildList({2, 6});
    vector<ListNode*> lists0 = {l1, l2, l3};

    ListNode* l4 = buildList({1, 2, 3});
    ListNode* l5 = buildList({1, 3, 4});
    ListNode* l6 = buildList({10, 11});
    vector<ListNode*> lists1 = {l4, l5, l6};

    ListNode* l7 = buildList({1});
    ListNode* l8 = buildList({1, 3, 4});
    ListNode* l9 = buildList({56});
    vector<ListNode*> lists2 = {l7, l8, l9};

    ListNode* merged0 = solution.mergeKLists(lists0);
    ListNode* merged1 = solution.mergeKLists(lists1);
    ListNode* merged2 = solution.mergeKLists(lists2);

    cout << "合併結果: ";
    printList(merged0);
    cout << "合併結果: ";
    printList(merged1);
    cout << "合併結果: ";
    printList(merged2);

    return 0;
}

