// Approach 1: Recursion+Memo
class Solution {
public:
    int n;
    int t[2501][2501];

    int solve(int i , int p , vector<vector<int>>& pairs){
        if(i == n) return 0;       //i = current index, p = previous index

        if(p != -1 && t[i][p] != -1)
            return t[i][p];

        int not_take = solve(i+1, p, pairs);

        int take = 0;

        if(p == -1 || pairs[i][0] > pairs[p][1]){
            take = 1 + solve(i+1, i, pairs);
        }

        if(p != -1)
            return t[i][p] = max(take, not_take);

        return max(take, not_take);
    }

    int findLongestChain(vector<vector<int>>& pairs) {
        memset(t, -1, sizeof(t));
        n = pairs.size();
        sort(pairs.begin() , pairs.end());

        return solve(0,-1,pairs);
    }
};