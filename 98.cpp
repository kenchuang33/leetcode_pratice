// Validate Binary Search Tree
#include <iostream>
#include <vector>
#include <climits>
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
// Top-Down
    bool isValidBST(TreeNode* root) {
        return helper(root, LLONG_MIN, LLONG_MAX);
    }

    bool helper(TreeNode* node, long long minVal, long long maxVal) {
        if (!node) return true;

        if (node->val <= minVal || node->val >= maxVal) //BST應該是要比 所有的左節點大（左節點的最大值） 和 比 所有右節點小（右節點最小值）
            return false;

        return helper(node->left, minVal, node->val) && //對於左邊的子節點 這個點的值會是最大值
               helper(node->right, node->val, maxVal); //對於右邊的子節點 這個點的值會是最小值
    }
};


class Solution1 {
public:
// bottom-up
    bool isValidBST(TreeNode* root) {
        int minVal, maxVal;
        return helper(root, minVal, maxVal);
    }

    bool helper(TreeNode* node, int &minVal, int &maxVal) {
        if (!node) {
            // 對空樹設初值，讓邏輯不會出錯
            minVal = INT_MAX;
            maxVal = INT_MIN;
            return true;
        }

        int leftMin, leftMax, rightMin, rightMax;
        bool leftBST = helper(node->left, leftMin, leftMax);//會更新參數的值
        bool rightBST = helper(node->right, rightMin, rightMax);

        // 檢查是否違反 BST 規則
        if (!leftBST || !rightBST) return false;
        if (node->left && leftMax >= node->val) return false;
        if (node->right && rightMin <= node->val) return false;

        // 更新當前這棵子樹的 minVal 與 maxVal
        minVal = node->left ? leftMin : node->val;
        maxVal = node->right ? rightMax : node->val;

        return true;
    }
};


