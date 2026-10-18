class Solution {
public:
    int minElements(vector<int>& nums, int limit, int goal) {
        long long int sum=0,diff;
        for(int x=0;x<nums.size();x++)
            sum+=nums[x];

        diff=(goal>=sum)? goal-sum:sum-goal;

        return (diff%limit)?diff/limit+1:diff/limit;
    }
};