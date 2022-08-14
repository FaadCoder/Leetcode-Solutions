class Solution {
    // digits, tight, isdistinct, mask
    int dp[11][2][1024];
    
    int getNumbers(string &str, int pos = 0, int tight = 1, int mask = 0)
    {
        if(pos == str.length())
        {
            return mask!=0;
        }
        
        if(dp[pos][tight][mask]!=-1)
            return dp[pos][tight][mask];
        
        int res = 0;
        
        if(tight)
        {
            for(int num = 0; num <= str[pos]-'0'; num++)
            {
                if(mask & (1<<num))
                    continue;
                
                int newMask = (mask==0 and num==0) ? mask : (mask | (1<<num));
                
                if(num == str[pos]-'0')
                    res += getNumbers(str, pos+1, 1, newMask);
                else
                    res += getNumbers(str, pos+1, 0, newMask);
            }
        }
        else
        {
            
            for(int num = 0; num <= 9; num++)
            {
                if(mask & (1<<num))
                    continue;
                
                int newMask = (mask==0 and num==0) ? mask : (mask | (1<<num));
                
                res += getNumbers(str, pos+1, 0, newMask);
            }
        }
        
        return dp[pos][tight][mask] = res; 
    }
    
public:
    int countSpecialNumbers(int n) {
        memset(dp, -1, sizeof(dp));
        string str = to_string(n);
        return getNumbers(str);
    }
};