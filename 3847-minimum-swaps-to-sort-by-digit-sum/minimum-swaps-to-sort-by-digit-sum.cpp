class Solution {
public:

    //finding the sum of the digits
    int digitSum(int num){
        int sum=0;
        while(num>0){
            sum+=num%10;
            num/=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> sortedNums=nums;

        //sort by digitsum then by actual value
        sort(sortedNums.begin(),sortedNums.end(),[this](int a,int b){
            int sumA=digitSum(a);
            int sumB=digitSum(b);
            if(sumA!=sumB) return sumA<sumB;
            return a<b;
        });

        //map these values to their index
        unordered_map<int,int> targetIndex;
        for(int i=0;i<n;i++){
            targetIndex[sortedNums[i]]=i;
        }

        vector<bool> visited(n,false);
        int swaps=0;

        //find count and cycle
        for(int i=0;i<n;i++){
            if(visited[i] || targetIndex[nums[i]]==i)
                continue;
            
            int cycleSize=0;
            int j=i;
            while(!visited[j]){
                visited[j]=true;
                j=targetIndex[nums[j]];
                cycleSize++;
            }
            swaps+=cycleSize-1;
        }
        return swaps;
    }
};