class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        if(p.size()>s.size()) return ans;
        vector<int> need(26,0);
        vector<int> window(26,0);

        for(char c:p){
            need[c-'a']++;
        }

        int k=p.size();
        for(int right=0;right<s.size();right++){
            window[s[right]-'a']++;
            if(right>=k){
                window[s[right-k]-'a']--;
            }
            if(window==need){
                ans.push_back(right-k+1);
            }
        }
        return ans;
    }
};