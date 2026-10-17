class Solution {
public:
    int solve(vector<int>& cost, int n, vector<int>& dp){
        if(n==0) return cost[0];
        if(n==1) return cost[1];

        //step3
        if(dp[n]!=-1)
            return dp[n];

        //step2 store in dp
        dp[n]=cost[n]+ min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return dp[n];
    }
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();

        //step1 create dp array
        vector<int> dp(n+1,-1);
        int ans=min(solve(cost,n-1,dp),solve(cost,n-2,dp));
        return ans;
    }
};