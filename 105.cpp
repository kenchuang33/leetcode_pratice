// Construct Binary Tree from Preorder and Inorder Traversal

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {


        if (preorder.empty()) return nullptr;

        int root_val=preorder[0];
        TreeNode* root = new TreeNode(root_val);

        vector<int> Left_inorder;
        vector<int> Right_inorder;
        bool find_inoder_root=false;

        for(auto i : inorder)
        {
            if(i==root_val) 
            {
              find_inoder_root=true;
              continue;
            }
            if(!find_inoder_root) Left_inorder.push_back(i);
            else Right_inorder.push_back(i);        
        }

        vector<int> Left_preorder(preorder.begin()+1, preorder.begin()+Left_inorder.size()+1);
        vector<int> Right_preorder(preorder.begin()+Left_inorder.size()+1, preorder.end());

        root->right=buildTree(Right_preorder, Right_inorder);
        root->left=buildTree(Left_preorder, Left_inorder);

        return root;
    }
};

class Solution1 {
public:
// O(N)
    unordered_map<int,int> mp;  // inorder 的值對應到 index
    vector<int> preorder;
    vector<int> inorder;

    TreeNode* build(int preL, int preR, int inL, int inR)
    {
        // 沒有節點了
        if (preL > preR) return nullptr;

        // preorder[preL] 一定是 root
        int root_val = preorder[preL];
        TreeNode* root = new TreeNode(root_val);

        // 在 inorder 中查 root index
        int mid = mp[root_val];

        // 左子樹節點數
        int leftSize = mid - inL;

        // 建左子樹
        root->left = build(preL + 1,
                           preL + leftSize,
                           inL,
                           mid - 1);

        // 建右子樹
        root->right = build(preL + leftSize + 1,
                            preR,
                            mid + 1,
                            inR);

        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) 
    {
        this->preorder = preorder;
        this->inorder = inorder;

        int n = preorder.size();
        if (n == 0) return nullptr;

        // 建立 inorder 的索引快取
        for (int i = 0; i < n; i++)
            mp[inorder[i]] = i;

        return build(0, n - 1, 0, n - 1);
    }
};
