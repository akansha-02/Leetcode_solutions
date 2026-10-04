class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses,0);

        //build graph
        for(auto p:prerequisites){
            int course=p[0];
            int prerequisite=p[1];

            adj[prerequisite].push_back(course);
            indegree[course]++;
        }

        queue<int> q;
        //push courses with 0 indegree
        for(int i=0;i<numCourses;i++){
            if(indegree[i]==0)
                q.push(i);
        }

        int count=0;
        //topological sort/bfs
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            count++;

            for(int next:adj[curr]){
                indegree[next]--;

                if(indegree[next]==0)
                    q.push(next);
            }
        }
        return count==numCourses;
    }
};