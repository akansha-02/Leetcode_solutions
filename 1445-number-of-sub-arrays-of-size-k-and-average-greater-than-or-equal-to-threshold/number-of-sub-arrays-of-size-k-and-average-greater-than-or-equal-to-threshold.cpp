class Solution {
public:
    int numOfSubarrays(vector<int>& arr, int k, int threshold) {
        
        int count=0;
        int sum=0;
        for(int right=0;right<arr.size();right++){

            //add right
            sum+=arr[right];

            //window size large remove 
            if(right>=k){
                sum-=arr[right-k];
            }

            //process
            if(right >= k - 1) {
                if(sum >= k * threshold) {
                    count++;
                }
            }
        }
        return count;
    }
};