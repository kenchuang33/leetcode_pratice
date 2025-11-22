// Subtree of Another Tree
/**
 * Definition for a binary tree node.
 */
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
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
       return dfs(root,subRoot);
    }

    bool sametree(TreeNode* a, TreeNode* b)
    {
        if (a==nullptr && b!=nullptr || a!=nullptr && b==nullptr) return false;

        if(a==nullptr && b==nullptr) return true;

        return sametree(a->left,b->left) && sametree(a->right,b->right) && a->val==b->val;

    }

    bool dfs(TreeNode* a, TreeNode* b)
    {
        if (a==nullptr) return false;
        if (sametree(a,b)) return true;
        return dfs(a->left,b) || dfs(a->right,b);
    }

   
};
int main() {
    Solution sol;

    // ✅ Test case 1: subRoot 是 root 的左子樹
    TreeNode* root1 = new TreeNode(3);
    root1->left = new TreeNode(4);
    root1->right = new TreeNode(5);
    root1->left->left = new TreeNode(1);
    root1->left->right = new TreeNode(2);

    TreeNode* subRoot1 = new TreeNode(4);
    subRoot1->left = new TreeNode(1);
    subRoot1->right = new TreeNode(2);

    cout << "Test 1 (should be true): " << boolalpha << sol.isSubtree(root1, subRoot1) << endl;


    // ❌ Test case 2: subRoot 結構不同（subRoot 少一個節點）
    TreeNode* subRoot2 = new TreeNode(4);
    subRoot2->left = new TreeNode(1);

    cout << "Test 2 (should be false): " << boolalpha << sol.isSubtree(root1, subRoot2) << endl;


    // ❌ Test case 3: subRoot 值一樣但結構不同（常見錯誤）
    TreeNode* root3 = new TreeNode(1);
    root3->left = new TreeNode(1);

    TreeNode* subRoot3 = new TreeNode(1);

    cout << "Test 3 (should be true): " << boolalpha << sol.isSubtree(root3, subRoot3) << endl;


    // ✅ Test case 4: subRoot 是一個單節點，root 有對應節點
    TreeNode* root4 = new TreeNode(2);
    root4->left = new TreeNode(3);
    root4->right = new TreeNode(4);

    TreeNode* subRoot4 = new TreeNode(4);

    cout << "Test 4 (should be true): " << boolalpha << sol.isSubtree(root4, subRoot4) << endl;


    return 0;
}
