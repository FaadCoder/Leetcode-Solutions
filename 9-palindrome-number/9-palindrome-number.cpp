class Solution {
public:
    bool isPalindrome(int x) {
        if(x<0)
            return false;
        long long int revertedNumber = 0;
        long long int originalNumber = x;
        
        while(x)
        {
            int lastDigit = x%10;
            revertedNumber *= 10;
            revertedNumber += lastDigit;
            x/=10;
        }
        
        cout<<revertedNumber;
        
        return (revertedNumber == originalNumber);
    }
};