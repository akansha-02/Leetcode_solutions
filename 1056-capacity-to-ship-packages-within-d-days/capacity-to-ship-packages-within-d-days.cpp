class Solution {
public:

    bool possible(vector<int>& weights,int days, long long capacity ){
        int requiredDays=1;
        long long currentCapacity=0;
        for(int w: weights){
            if(currentCapacity+w<=capacity){
                currentCapacity+=w;
            }else{
                requiredDays++;
                currentCapacity=w;
            }
        }
        return requiredDays<=days;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long long low=*max_element(weights.begin(),weights.end());
        long long high=accumulate(weights.begin(),weights.end(),0LL);

        while(low<high){
            long long mid=low+(high-low)/2;

            if(possible(weights,days,mid))
                 high=mid;
            else
                low=mid+1;
        }
        return low;
    }
};