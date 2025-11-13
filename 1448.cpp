//Count Good Nodes in Binary Tree

/**
 * Definition for a binary tree node.
 */
#include <iostream>
#include <vector>
#include <queue>
using namespace std;
struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
class Solution {
public:
    int sum=0;
    int goodNodes(TreeNode* root) {
        dfs(root->right,root->val);
        dfs(root->left,root->val);

        return sum+1;
        
    }
    void dfs(TreeNode* root, int max_num)
    {
        if (root==nullptr) return;

        if (root->val >= max_num)
        {
            sum++;
            max_num=root->val;
        }
        dfs(root->right,max_num);
        dfs(root->left,max_num);

    }
};
TreeNode* buildTree(vector<int> vals) {
    if (vals.empty() || vals[0] == -1) return nullptr;
    TreeNode* root = new TreeNode(vals[0]);
    queue<TreeNode*> q;
    q.push(root);
    int i = 1;
    while (!q.empty() && i < vals.size()) {
        TreeNode* node = q.front(); q.pop();
        if (vals[i] != -1) {
            node->left = new TreeNode(vals[i]);
            q.push(node->left);
        }
        i++;
        if (i < vals.size() && vals[i] != -1) {
            node->right = new TreeNode(vals[i]);
            q.push(node->right);
        }
        i++;
    }
    return root;
}

// ---------------------------
// main 測試區
// ---------------------------
int main() {
    Solution sol;

    // ✅ 測資 1
    // Tree: [3,1,4,3,-1,1,5]
    // 結構：
    //         3
    //       /   \
    //      1     4
    //     /     / \
    //    3     1   5
    TreeNode* root1 = buildTree({3,1,4,3,-1,1,5});
    cout << "Test1 → Good nodes = " << sol.goodNodes(root1) << endl; // 預期輸出: 4

    // ✅ 測資 2
    // Tree: [3,3,null,4,2]
    // 結構：
    //        3
    //       /
    //      3
    //     / \
    //    4   2
    Solution sol2;
    TreeNode* root2 = buildTree({3,3,-1,4,2});
    cout << "Test2 → Good nodes = " << sol2.goodNodes(root2) << endl; // 預期輸出: 3

    // ✅ 測資 3
    // Tree: [1]
    Solution sol3;
    TreeNode* root3 = buildTree({1});
    cout << "Test3 → Good nodes = " << sol3.goodNodes(root3) << endl; // 預期輸出: 1

    // ✅ 測資 4
    // Tree: [9,8,10,-1,7,9,11]
    // 結構：
    //         9
    //       /   \
    //      8    10
    //       \   / \
    //        7 9  11
    Solution sol4;
    TreeNode* root4 = buildTree({9,8,10,-1,7,9,11});
    cout << "Test4 → Good nodes = " << sol4.goodNodes(root4) << endl; // 預期輸出: 3

    return 0;
}