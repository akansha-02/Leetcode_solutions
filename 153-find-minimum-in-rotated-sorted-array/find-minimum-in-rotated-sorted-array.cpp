class Solution {
public:
    int findMin(vector<int>& nums) {
        int low=0;
        int high=nums.size()-1;
        while(low<high){
            int mid=low+(high-low)/2;

            //min at right side
            if(nums[mid]>nums[high]){
                low=mid+1;
            }
            else{
                high=mid;   //min at left or mid itself
            }
        }
        return nums[low];
    }
};