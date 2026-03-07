//  Serialize and Deserialize Binary Tree
#include <vector>
#include <queue>
#include <string>
using namespace std;
  
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return "#,";
        
        string ans="";
        ans.append(to_string(root->val));
        ans.append(",");

        ans.append(serialize(root->left)); 
        ans.append(serialize(root->right));

        return ans;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        queue<string> q;
        string temp="";
        for(auto& c: data)
        {
            if (c==',')
            {
                q.push(temp);
                temp="";
            } 
            else temp+=c;
        }


        if(!temp.empty()) q.push(temp);

        return solve(q);
    }

    TreeNode* solve(queue<string> & q) {
        if (q.empty()) return nullptr;

        string cur=q.front();
        q.pop();

        if (cur=="#") return nullptr;

        TreeNode* curnode=new TreeNode(stoi(cur));

        curnode->left=solve(q);
        curnode->right=solve(q);

        return curnode;


    }

};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));