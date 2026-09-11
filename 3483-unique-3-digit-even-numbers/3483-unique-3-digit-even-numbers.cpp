class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        vector<int> freq(10, 0);

        for (int d : digits) {
            freq[d]++;
        }

        int ans = 0;

        // Hundreds digit
        for (int a = 1; a <= 9; a++) {
            if (freq[a] == 0) continue;

            freq[a]--;

            // Tens digit
            for (int b = 0; b <= 9; b++) {
                if (freq[b] == 0) continue;

                freq[b]--;

                // Units digit must be even
                for (int c = 0; c <= 8; c += 2) {
                    if (freq[c] > 0) {
                        ans++;
                    }
                }

                freq[b]++;
            }

            freq[a]++;
        }

        return ans;
    }
};
