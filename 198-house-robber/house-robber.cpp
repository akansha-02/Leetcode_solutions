class Solution {
public:
    int rob(vector<int>& nums) {
        int n=nums.size();
        int prev1=0;
        int prev2=0;
        for(int i=0;i<n;i++){
            int incl=nums[i]+prev2;
            int excl=prev1;
            int curr=max(incl,excl);

            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
};