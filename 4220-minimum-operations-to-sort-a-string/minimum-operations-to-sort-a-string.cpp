class Solution {
public:
    int minOperations(string s) {
        int n=s.size();

        //already sorted
        if(is_sorted(s.begin(),s.end()))
            return 0;

        //string length is 2 can't sort
        if(n==2)
            return -1;
        
        char mn=*min_element(s.begin(),s.end());
        char mx=*max_element(s.begin(),s.end());
        //min or max char is at first or end resp
        if(s[0]==mn || s[n-1]==mx)
            return 1;

        //min or max is at middle
        for(int i=1;i<n-1;i++){
            if(s[i]==mn || s[i]==mx)
                return 2;
        }

        return 3;
    }
};