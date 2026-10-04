class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        for(auto p:prerequisites){
            int course=p[0];
            int prerequisite=p[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;

        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }

        vector<int> ans;
        while(!q.empty()){
            int curr=q.front();
            q.pop();

            ans.push_back(curr);
            for(int next:adj[curr]){
                indegree[next]--;

                if(indegree[next]==0)
                    q.push(next);
            }
        }
        if(ans.size()!=numCourses)
            return {};
        return ans;

    }
};