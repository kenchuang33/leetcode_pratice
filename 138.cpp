// Copy List with Random Pointer
/*
// Definition for a Node.

*/
#include <vector>
#include <unordered_map>
using namespace std;

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};


class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* old_forindex = head;
        unordered_map<Node*, int> Oldrc;
        unordered_map<int, Node*> Newrc;

        int oldrc_index=0;
        while(old_forindex)
        {
            Oldrc[old_forindex]=oldrc_index;
            oldrc_index++;
            old_forindex=old_forindex->next;
        }

        Node* old = head;
        Node* dummy= new Node(0);
        Node* new_prev=dummy;

        int newrc_index=0;
        while(old)
        {
            Node* cur;
            // val
            if (Newrc.count(newrc_index))
            {
                cur = Newrc[newrc_index];
                cur->val=old->val;
            }
            else
            {
                cur =new Node(old->val);
                Newrc[newrc_index]=cur;
            }

            new_prev->next=cur;
            new_prev=cur;
            
            // random
            if(!old->random) cur->random=nullptr;
            else if(Newrc.count(Oldrc[old->random]))
            {
                cur->random=Newrc[Oldrc[old->random]];
            }
            else
            {
                Node* temp= new Node(0);
                cur->random=temp;
                Newrc[Oldrc[old->random]]=temp;
            }

            newrc_index++;
            old=old->next;            

        }

        new_prev->next=nullptr;
        return dummy->next;

    }
};

class Solution1 {
public:
// 進行兩次步驟 先把所有點建好，在連起來
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        unordered_map<Node*, Node*> nodeMap;

        // 第一步：複製所有節點，只設 val，不連接 next、random
        Node* old = head;
        while (old) {
            nodeMap[old] = new Node(old->val);
            old = old->next;
        }

        // 第二步：設置 next 和 random 指標
        old = head;
        while (old) {
            nodeMap[old]->next = nodeMap[old->next];       // 注意：nullptr 也沒問題
            nodeMap[old]->random = nodeMap[old->random];   // nullptr 也會正確處理
            old = old->next;
        }

        return nodeMap[head]; // 回傳新頭節點
    }
};

class Solution {
public:
// O(1) 把新舊點接再一起(畫出來比較容易理解)
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;

        // 步驟一：在原節點後插入複製節點
        Node* cur = head;
        while (cur) {
            Node* copy = new Node(cur->val);
            copy->next = cur->next;
            cur->next = copy;
            cur = copy->next;
        }

        // 步驟二：設定 random 指標
        cur = head;
        while (cur) {
            if (cur->random)
                cur->next->random = cur->random->next;
            cur = cur->next->next;
        }

        // 步驟三：拆出新鏈表
        Node* dummy = new Node(0);
        Node* new_cur = dummy;
        cur = head;
        while (cur) {
            new_cur->next = cur->next;
            cur->next = cur->next->next;

            new_cur = new_cur->next;
            cur = cur->next;
        }

        return dummy->next;
    }
};
