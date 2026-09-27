//Approach-1 (Brute Force)
//T.C : O(n^2)
//S.C : O(n)
class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> lastSkipLength; 
        string result;

        for (char currentChar : s) {
            if (currentChar == '(') {
                lastSkipLength.push(result.length());
            } 
            else if (currentChar == ')') {
                int start = lastSkipLength.top();
                lastSkipLength.pop();
                reverse(result.begin() + start, result.end());
            } 
            else {
                result += currentChar;
            }
        }
        return result;
    }
};