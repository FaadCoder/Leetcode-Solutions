class Solution {
public:
    int getSum(int x, int y) {
            while (y != 0)
    {
        // carry should be unsigned to
        // deal with -ve numbers
        // carry now contains common
        //set bits of x and y
        unsigned carry = x & y;
 
        // Sum of bits of x and y where at
        //least one of the bits is not set
        x = x ^ y;
 
        // Carry is shifted by one so that adding
        // it to x gives the required sum
        y = carry << 1;
    }
    return x;
    }
};