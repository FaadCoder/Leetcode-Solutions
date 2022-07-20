class Solution {
public:
    int trailingZeroes(int n) {
        int zeroes = 0;
        int fivePower = 5;
        while(n)
        {
            zeroes += n/fivePower;
            n/=fivePower;
        }
        
        return zeroes;
    }
};