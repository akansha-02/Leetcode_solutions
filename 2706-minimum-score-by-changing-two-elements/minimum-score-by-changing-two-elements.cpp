class Solution {
public:
    int minimizeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int n=nums.size();

        //change two smallest
        int a=nums[n-1]-nums[2];

        //change one smallest and one largest
        int b=nums[n-2]-nums[1];

        //change two largest
        int c=nums[n-3]-nums[0];

        return min({a,b,c});
    }
};