class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int maxProfit = 0;

        for(int price : prices) {

            //minimum buying price
            minPrice = min(minPrice, price);

            //profit if we sell today
            int profit = price - minPrice;

            //maximum profit
            maxProfit = max(maxProfit, profit);
        }

        return maxProfit;
    }
};