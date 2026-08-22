class Solution {
public:
    bool checkInclusion(string s1, string s2) {
         int n = s1.size();
        int m = s2.size();

        if (n > m)
            return false;

        vector<int> freq1(26, 0);
        vector<int> freq2(26, 0);

        // Frequency of characters in s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        // First window of s2
        for (int i = 0; i < n; i++) {
            freq2[s2[i] - 'a']++;
        }

        // Check first window
        if (freq1 == freq2)
            return true;

        // Slide the window
        for (int right = n; right < m; right++) {

            // Add new character
            freq2[s2[right] - 'a']++;

            // Remove old character
            freq2[s2[right - n] - 'a']--;

            // Check if frequencies match
            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};