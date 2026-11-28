
class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {

        int n = items.size();

        vector<int> freq(n + 1, 0);
        vector<int> cnt(n + 1, 0);

        int minPrice = INT_MAX;

        // Calculate frequency of each factor
        for(auto& item : items) {
            freq[item[0]]++;
            minPrice = min(minPrice, item[1]);
        }

        // Calculate number of eligible free items
        for(int i = 1; i <= n; i++) {

            for(int j = i; j <= n; j += i) {
                cnt[i] += freq[j];
            }

            cnt[i]--;
        }

        // Sort by price
        sort(items.begin(), items.end(),
        [](const vector<int>& a, const vector<int>& b) {
            return a[1] < b[1];
        });

        long long ans = 0;

        // Select premium purchases
        for(auto& item : items) {

            int factor = item[0];
            int price = item[1];

            if(price > 2LL * minPrice) {
                break;
            }

            if(cnt[factor] == 0)
                continue;

            int take = min(cnt[factor], budget / price);

            ans += 2LL * take;
            budget -= take * price;
        }

        // Purchase additional cheapest items
        ans += budget / minPrice;

        return (int)ans;
    }
};
