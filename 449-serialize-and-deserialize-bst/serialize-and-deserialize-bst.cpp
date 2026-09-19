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

    void solve1(TreeNode* root, string &s) {
        if(root == NULL) return;

        s += to_string(root->val) + ",";

        solve1(root->left, s);
        solve1(root->right, s);
    }

    string serialize(TreeNode* root) {
        string s;
        solve1(root, s);
        return s;
    }

    TreeNode* solve2(vector<int>& nums, int &index,
                     long long low, long long high) {

        if(index == nums.size())
            return NULL;

        int val = nums[index];

        if(val < low || val > high)
            return NULL;

        index++;

        TreeNode* root = new TreeNode(val);

        root->left = solve2(nums, index, low, val);
        root->right = solve2(nums, index, val, high);

        return root;
    }

    TreeNode* deserialize(string data) {

        stringstream ss(data);
        string value;
        vector<int> nums;

        while(getline(ss, value, ',')) {
            if(!value.empty())
                nums.push_back(stoi(value));
        }

        int index = 0;

        return solve2(nums, index, LLONG_MIN, LLONG_MAX);
    }
};

// Your Codec object will be instantiated and called as such:
// Codec* ser = new Codec();
// Codec* deser = new Codec();
// string tree = ser->serialize(root);
// TreeNode* ans = deser->deserialize(tree);
// return ans;