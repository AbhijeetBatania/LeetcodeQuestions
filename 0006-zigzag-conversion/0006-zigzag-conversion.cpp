class Solution {
public:
    string convert(string s, int numRows) {
        if(numRows == 1) return s;

        string ans;
        vector<string> rows(numRows); 

        int rowIdx = 0;
        int i = 0;

        while(i < s.size()){
            while(i < s.size() && rowIdx < numRows){
                rows[rowIdx] += s[i];
                i++;
                rowIdx++;
            }
        
            rowIdx -= 2;

            while(i < s.size() && rowIdx > 0){
                rows[rowIdx] += s[i];
                i++;
                rowIdx--;
            }
        }

        for(auto & row : rows){
            ans += row;
        }

        return ans;
    }
};
