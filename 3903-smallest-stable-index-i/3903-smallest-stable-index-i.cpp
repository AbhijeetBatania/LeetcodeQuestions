class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n = nums.size();

        int maxi = INT_MIN;
        int mini = INT_MAX;

        vector<int> min_val(n);

        for(int i = n-1; i>=0 ; i--){
            mini = min(mini, nums[i]);
            min_val[i] = mini;
        }

        for(int i = 0 ; i < nums.size() ; i++){
            maxi = max(maxi, nums[i]);
            int score = maxi - min_val[i];
            if(score <= k){
                return i;
            }
        }
        return -1;
    }
};