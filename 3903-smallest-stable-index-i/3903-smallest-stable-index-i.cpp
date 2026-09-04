class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int maxi = INT_MIN;
        for(int i = 0 ; i < nums.size() ; i++){
            maxi = max(maxi, nums[i]);
            int mini = *min_element(nums.begin()+i , nums.end());
            int score = maxi - mini;
            if(score <= k){
                return i;
            }
        }
        return -1;
    }
};