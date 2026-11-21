
class Solution {
public:
    vector<vector<int>> tree, newTree;
    vector<int> ans, lastSeen;
    string str;

    void build(int u, vector<int>& parent) {

        int c = str[u] - 'a';

        int old = lastSeen[c];

        // Find the closest matching ancestor
        int p;

        if(old != -1)
            p = old;
        else
            p = parent[u];

        // Build modified tree
        if(p != -1)
            newTree[p].push_back(u);

        // Mark current node as the latest ancestor
        lastSeen[c] = u;

        // Traverse original tree
        for(int v : tree[u]) {
            build(v, parent);
        }

        // Backtrack
        lastSeen[c] = old;
    }

    int dfs(int u) {

        int size = 1;

        for(int v : newTree[u]) {
            size += dfs(v);
        }

        ans[u] = size;

        return size;
    }

    vector<int> findSubtreeSizes(
        vector<int>& parent, string s) {

        int n = parent.size();

        str = s;

        tree.resize(n);
        newTree.resize(n);
        ans.resize(n);

        lastSeen.assign(26, -1);

        // Build original tree
        for(int i = 1; i < n; i++) {
            tree[parent[i]].push_back(i);
        }

        // Construct modified tree
        build(0, parent);

        // Calculate subtree sizes
        dfs(0);

        return ans;
    }
};
