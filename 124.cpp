// Binary Tree Maximum Path Sum
#include <iostream>

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
    int maxPathSum(TreeNode* root) {
        int res=root->val;
        dfs(root, res);
        return res;
    }
    
    int dfs(TreeNode* root, int& res)
    {
        if(!root) return 0;

        int l=dfs(root->left, res);
        int r=dfs(root->right, res);
        if(l<0) l=0; //如果負的就不考慮 不然會忽略可以只選本身root->val
        if(r<0) r=0;
        res=max(res, l+r+root->val);

        return max(l,r)+root->val;
    }
};