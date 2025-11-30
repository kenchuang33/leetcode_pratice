// Binary Tree Level Order Traversal
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
    vector<vector<int>> levelOrder(TreeNode* root) {
        
        vector<vector<int>> res;
        queue < TreeNode* > q;
        
        if (!root) return {};
        q.push(root);
        
        while(!q.empty())
        {
            int len=q.size();

            vector<int> layer;
            for(int i=0; i<len; i++)
            {
                TreeNode* curnode=q.front();
                q.pop();
                
                layer.push_back(curnode->val);
                
                if(curnode->left) q.push(curnode->left);
                if(curnode->right) q.push(curnode->right);
            }
            res.push_back(layer);

        }
        return res;

    }

};