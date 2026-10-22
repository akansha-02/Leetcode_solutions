class Solution {
public:
    // bool solve(int index, int target, vector<int>& nums){
    //     if(target==0) return true;
    //     if(index==nums.size()) return false;

    //     if(dp[index][target]!=-1)
    //         return dp[index][target];
    //     bool excl=solve(index+1,target,nums);
    //     bool incl=false;
    //     if(nums[index]<=target)
    //         incl=solve(index+1,target-nums[index],nums);
    
    //     return dp[index][target]= (incl || excl);
    // }

    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum%2!=0)
            return false;
        int target=sum/2;
        vector<bool> dp(target+1,false);
        dp[0]=true;
        for(int n: nums){
            for(int s=target;s>=n;s--){
                dp[s]=dp[s]||dp[s-n];
            }
        }

        return dp[target];
    }
};