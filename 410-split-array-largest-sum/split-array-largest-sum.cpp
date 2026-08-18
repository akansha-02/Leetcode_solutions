class Solution {
public:

    bool possible(vector<int>& nums,int k,long long limit){
        int parts=1;
        long long sum=0;
        for(int n:nums){
            if(sum+n<=limit){
                sum+=n;
            }else{
                parts++;
                sum=n;
            }
        }
        return parts<=k;
    }

    int splitArray(vector<int>& nums, int k) {
        long long low=*max_element(nums.begin(),nums.end());
        long long high=accumulate(nums.begin(),nums.end(),0LL);

        while(low<high){
            long long mid=low+(high-low)/2;

            if(possible(nums,k,mid))
                high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};