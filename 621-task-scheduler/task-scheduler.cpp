class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        unordered_map<int,int> freq;
        for(int x: tasks){
            freq[x]++;
        }

        priority_queue<int> pq;
        for(auto &it: freq){
            pq.push(it.second);
        }

        queue<pair<int,int>> q;
        int time=0;
        while(!pq.empty() || !q.empty()){
            time++;
            if(!pq.empty()){
                int count=pq.top();
                pq.pop();
                count--;
                if(count>0)
                q.push({count,time+n});
            }
        
            if(!q.empty() && q.front().second==time){
                pq.push(q.front().first);
                q.pop();
            }
        }
        return time;
    }
};