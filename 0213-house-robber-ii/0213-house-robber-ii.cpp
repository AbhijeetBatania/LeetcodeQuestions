class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        
        vector<int> dp(n+1, 0);
        //dp[i] = Max money gained from i houses
        
        int result1 = 0;
        int result2 = 0;
        
        //Case-1 (Take from 1st House - Hence skip the last house)
        dp[0] = 0;
        for(int i = 1; i<=n-1; i++) {
            dp[i] = max(dp[i-1] , nums[i-1]+ ((i-2 >= 0) ? dp[i-2] : 0 ));
        }
        result1 = dp[n-1];
        
        dp.clear();
        //Case-2 (Take from 2nd House - Hence take the last house)
        dp[0] = 0;
        dp[1] = 0;
        for(int i = 2; i<=n; i++) {
            dp[i] = max(dp[i-1] , nums[i-1]+ ((i-2 >= 0) ? dp[i-2] : 0 ));
        }
        result2 = dp[n];
        
        return max(result1, result2);
    }
};