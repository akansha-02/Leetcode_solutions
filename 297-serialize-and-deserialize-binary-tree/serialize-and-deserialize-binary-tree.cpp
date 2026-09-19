/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:
    void solve1(TreeNode* root,string &s){
        if(root==NULL){
            s+="#,";
            return ;
        }
        s+=to_string(root->val)+",";
        solve1(root->left,s);
        solve1(root->right,s);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s;
        solve1(root,s);
        return s;
    }

    TreeNode* solve2(stringstream &ss){
        string value;
        if(!getline(ss, value, ','))
            return NULL;

        if(value=="#") return NULL;
        TreeNode* root=new TreeNode(stoi(value));
        root->left=solve2(ss);
        root->right=solve2(ss);
        return root;
    }
    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return solve2(ss);

    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));