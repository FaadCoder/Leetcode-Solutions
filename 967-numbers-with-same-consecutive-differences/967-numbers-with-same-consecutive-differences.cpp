class Solution {
public:
    vector<int> numsSameConsecDiff(int n, int k) {
        vector<int> currSet(9);
        iota(begin(currSet), end(currSet), 1);
        
        for(int len = 2; len <= n; len++)
        {
            vector<int> nextSet;
            
            for(int num : currSet)
            {
                int lastDigit = num % 10;
                
                if(lastDigit + k <= 9)
                    nextSet.push_back(num * 10 + lastDigit + k);
                
                if(k > 0 and lastDigit - k >= 0)
                    nextSet.push_back(num * 10 + lastDigit - k);
            }
            
            currSet = nextSet;
        }
        
        return currSet;
    }
};