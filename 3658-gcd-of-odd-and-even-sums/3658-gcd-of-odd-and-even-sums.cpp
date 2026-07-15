class Solution {
public:
    int gcd(int a, int b) {  //Euclidean Algorithm
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }
        return a;
    }
    int gcdOfOddEvenSums(int n) {
        int oddSum = n * n;
        int evenSum = n * (n + 1);

        return gcd(evenSum, oddSum);
    }
};