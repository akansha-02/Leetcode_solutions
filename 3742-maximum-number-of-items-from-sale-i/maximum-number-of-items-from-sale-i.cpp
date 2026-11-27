class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n=items.size();
        vector<int> freeCount(n,0);
        int minPrice=INT_MAX;

        //calculate free copies and min price
        for(int i=0;i<n;i++){
            minPrice=min(minPrice,items[i][1]);
            for(int j=0;j<n;j++){
                if(i!=j && items[j][0]%items[i][0]==0)
                    freeCount[i]++;
            }
        }

        // 0/1 knapsack DP
        vector<int> dp(budget+1,0);
        for(int i=0;i<n;i++){
            int price=items[i][1];
            int gain=freeCount[i]+1;
            for(int j=budget;j>=price;j--){
                dp[j]=max(dp[j],dp[j-price]+gain);
            }
        }
        int ans=0;
        for(int j=0;j<=budget;j++){
            int rem=budget-j;
            ans=max(ans,dp[j]+rem/minPrice);
        }
        return ans;
    }
};