// Clone Graph
#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
using namespace std;
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

class Solution {
public:    
    //BFS
    Node* cloneGraph(Node* node) {
        queue<Node*> q;
        unordered_map<Node*, Node*> visited;

        if (!node) return {};

        Node* head= new Node(node->val);
        visited[node]=head;
        q.push(node);

        while(!q.empty())
        {
            Node* cur=q.front();
            q.pop();

            for(auto n : cur->neighbors)
            {
                if(!visited.count(n))
                {
                    visited[n]=new Node(n->val);
                    q.push(n);
                }
                visited[cur]->neighbors.push_back(visited[n]);
             }
        }

        return head;
    }
};

class Solution1 {
public:    
    //DFS 
    Node* cloneGraph(Node* node) {
        unordered_map<Node*, Node*> visited;

        if (!node) return nullptr;

        return dfs(node, visited); // 回傳整個 clone 的起點（包含自己）
    }

    Node* dfs(Node* node, unordered_map<Node*, Node*> &visited)
    {
        if (!node) return nullptr;

        // 如果已經 clone 過，直接回傳
        if (visited.count(node)) return visited[node];

        // 先建立 clone 節點（空的 neighbors），登記
        Node* copy = new Node(node->val);
        visited[node] = copy;

        // 遞迴處理 neighbors
        for (Node* neighbor : node->neighbors) {
            copy->neighbors.push_back(dfs(neighbor, visited));
        }

        return copy;
    }
};

class Solution2 {
public:
    //DFS    
    unordered_map<Node*, Node*> visited;

    Node* cloneGraph(Node* node) {
        if (!node) return nullptr;

        visited[node] = new Node(node->val); // 建立第一個 clone
        dfs(node); // 開始 DFS 遞迴
        return visited[node]; // 回傳第一個 clone 節點
    }

    void dfs(Node* node) {
        for (Node* neighbor : node->neighbors) {
            if (!visited.count(neighbor)) {
                visited[neighbor] = new Node(neighbor->val);
                dfs(neighbor); // 遞迴處理這個 neighbor
            }

            // 加到目前 node 的 clone 的 neighbors 中
            visited[node]->neighbors.push_back(visited[neighbor]);
        }
    }
};

