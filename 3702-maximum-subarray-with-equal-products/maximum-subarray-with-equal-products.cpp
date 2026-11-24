class Solution {
public:
    int maxLength(vector<int>& nums) {
        int n=nums.size();
        int maxNum=0;
        int maxLcm=1;
        for(int x:nums){
            maxNum=max(maxNum,x);
            maxLcm=lcm(maxLcm,x);
        }
        long long limit=1LL*maxNum*maxLcm;
        int ans=0;

        for(int i=0;i<n;i++){
            long long product=1;
            long long g=0;
            long long l=1;
            for(int j=i;j<n;j++){
                product*=nums[j];
                if(product>limit)
                    break;
                g=gcd(g,(long long)nums[j]);
                l=lcm(l,(long long)nums[j]);

                if(product==g*l)
                    ans=max(ans,(j-i+1));
            }
        }
        return ans;
    }
};