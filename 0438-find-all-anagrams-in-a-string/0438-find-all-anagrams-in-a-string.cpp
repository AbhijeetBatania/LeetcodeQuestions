class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;

        if (p.size() > s.size()) return ans;

        vector<int> freqP(26, 0);
        vector<int> freqWindow(26, 0);

        // Frequency of characters in p
        for (char c : p) {
            freqP[c - 'a']++;
        }

        int k = p.size();

        // First window
        for (int i = 0; i < k; i++) {
            freqWindow[s[i] - 'a']++;
        }

        if (freqWindow == freqP)
            ans.push_back(0);

        // Slide the window
        for (int i = k; i < s.size(); i++) {
            // Add new character
            freqWindow[s[i] - 'a']++;

            // Remove old character
            freqWindow[s[i - k] - 'a']--;

            int start = i - k + 1;

            if (freqWindow == freqP)
                ans.push_back(start);
        }

        return ans;
    }
};
