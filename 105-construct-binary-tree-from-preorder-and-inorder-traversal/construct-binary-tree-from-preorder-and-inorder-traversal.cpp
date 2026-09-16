/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int &index,int left,int right,unordered_map<int,int>& mp){
        if(left>right) return NULL;

        //first element of preorder is root
        int value=preorder[index++];
        TreeNode* root=new TreeNode(value);

        //pos in inorder
        int pos=mp[value];
        
        //left subtree
        root->left=solve(preorder,inorder,index,left,pos-1,mp);

        //right subtree
        root->right=solve(preorder,inorder,index,pos+1,right,mp);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }

        int index=0;

        return solve(preorder,inorder,index,0,inorder.size()-1,mp);
    }
};