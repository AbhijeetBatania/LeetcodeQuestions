class Solution {
public:
    int maxProduct(int n) {
        int ans=0;

        int max_digit = n%10;
        n/=10; 

        while(n > 0){
            int digit = n%10;
            n/=10; 
            
            ans = max(max_digit*digit , ans);

            max_digit = max(max_digit, digit) ;
        }
        return ans;
    }
};