class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        //sort by width and height
        sort(envelopes.begin(),envelopes.end(), [](vector<int>& a, vector<int>& b){
            if(a[0]==b[0])
                return a[1]>b[1];
            return a[0]<b[0];
        });

        //find longest inc subsequence
        vector<int> dp;
        for(auto& e:envelopes){
            int height=e[1];
            auto it=lower_bound(dp.begin(),dp.end(),height);

            if(it==dp.end())
                dp.push_back(height);
            else
                *it=height;
        }
        return dp.size();
    }
};