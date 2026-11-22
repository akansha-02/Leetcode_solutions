class Solution {
public:
    bool checkString(string s) {
        int pos=s.find('b');
        if(pos==string::npos)
            return true;
        for(int i=pos;i<s.size();i++){
            if(s[i]=='a')
                return false;
        }
        return true;
    }
};