class Solution {
public:
    int solve(vector<int>& nums, int k){
        int n=nums.size();
        int prevMax=INT_MIN;
        for(int start=0;start<n;start+=k){
            int end=start+k-1;
            int mn=nums[start];
            int mx=nums[start];
            int descents=0;

            for(int i=start;i<=end;i++){
                mn=min(mn,nums[i]);
                mx=max(mx,nums[i]);

                int next=(i==end)?start:i+1;
                if (nums[i] > nums[next])
                    descents++;
            }
            if(descents>1) 
                return false;
            
            if (start > 0 && prevMax > mn) {
                return false;
            }
            
            prevMax=mx;
        }
        return true;
    }
    int sortableIntegers(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        for(int k=1;k*k<=n;k++){
            if(n%k!=0)
                continue;
        
            if(solve(nums,k))
                ans+=k;

            int other=n/k;

            if(other!=k && solve(nums,other))
                ans+=other;
        }
        return ans;
    }
};