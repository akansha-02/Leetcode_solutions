class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int n=nums.size();
        int sum=0;
        for(int i=0;i<k;i++){
            sum+=nums[i];
        }
        int maxSum=sum;
        // int left=0;
        for(int right=k;right<n;right++){
            // sum=sum+nums[right]-nums[left];
            sum+=nums[right];
            sum-=nums[right-k];
            maxSum=max(maxSum,sum);
        }
        return (double)maxSum/k;
    }
};