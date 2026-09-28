class Solution {
public:
    int maxDepth(string s) {
        int ans = 0 , temp = 0;
        for(char ch : s){
            if(ch == '(') temp++;
            else if (ch == ')') temp--;
            else continue;
            ans = max(temp,ans);
        }
        return ans;
    }
};