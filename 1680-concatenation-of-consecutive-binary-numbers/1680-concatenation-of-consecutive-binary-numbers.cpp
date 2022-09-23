class Solution {
    const int MOD = 1e9 + 7;
    
public:
    int concatenatedBinary(int n) {
        long long int result = 0;
        int length = 0;
        
        for(int number = 1; number <= n; number++)
        {
            length += ((number & (number - 1)) == 0);
            result = ((result << length) | number) %MOD;
        }
        
        return result;
    }
};
