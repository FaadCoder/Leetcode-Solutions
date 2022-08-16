class Solution {
    
    int dp[11][11][2][11];
    
    int getCount(string &str, int width, int d, int pos = 0, int tight = 1, int count = 0)
    {
        if(pos == width)
            return count;
        
        if(dp[width][pos][tight][count]!=-1)
            return dp[width][pos][tight][count];
        
        int res = 0;
        
        if(tight)
        {
            int start = (pos == 0) ? 1 : 0;
            for(int digit = start; digit <= str[pos] - '0'; digit++)
                res += getCount(str, width, d, pos + 1, (digit < (str[pos] - '0')) ? 0 : 1, count + (digit == d));
            
        }
        else
        {
            int start = (pos == 0) ? 1 : 0;
            for(int digit = start; digit <= 9; digit++)
                res += getCount(str, width, d, pos + 1, 0, count + (digit == d));
        }
        
        return dp[width][pos][tight][count] = res;
    }
    
    int digitsCountHelper(int d, int num)
    {
        string str = to_string(num);
        int digitCount = 0;
        
        memset(dp, -1, sizeof(dp));
        
        for(int width = 1; width <= str.length(); width++)
            digitCount += getCount(str, width, d, 0, (width < str.length()) ? 0 : 1);
        
        return digitCount;
    }
    
public:
    int digitsCount(int d, int low, int high) {
        
        return digitsCountHelper(d, high) - digitsCountHelper(d, low - 1);
        
    }
};