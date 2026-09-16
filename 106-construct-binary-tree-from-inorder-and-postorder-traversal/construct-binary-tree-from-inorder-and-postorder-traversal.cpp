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
    TreeNode* solve(vector<int>& inorder, vector<int>& postorder, int &index, int left,int right, unordered_map<int,int> &mp){
        if(left>right) return NULL;

        int value=postorder[index--];
        TreeNode* root=new TreeNode(value);

        int pos=mp[value];
        root->right=solve(inorder,postorder,index,pos+1,right,mp);
        root->left=solve(inorder,postorder,index,left,pos-1,mp); 
        return root;
    }
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        unordered_map<int,int> mp;
        for(int i=0;i<inorder.size();i++){
            mp[inorder[i]]=i;
        }
        int index=postorder.size()-1;
        return solve(inorder,postorder,index,0,inorder.size()-1,mp);
    }
};