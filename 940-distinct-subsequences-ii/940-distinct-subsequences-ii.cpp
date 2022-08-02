class Solution {
    
    const int MOD = 1e9 + 7;
    
    int addUnderMod(int a,int b)
    {
        return (a%MOD + b%MOD)%MOD;
    }
    
    int prodUnderMod(int a,int b)
    {
        return (a%MOD * b%MOD) %MOD;
    }
    
    int subUnderMod(int a,int b)
    {
        return (a%MOD - b%MOD + MOD)%MOD;
    }
    
public:
    int distinctSubseqII(string s) {
        int dp[s.length()+1];
        int lastOcc[26];
        memset(lastOcc,-1,sizeof(lastOcc));
        dp[0] = 1;
        
        for(int idx = 1; idx<=s.length(); idx++)
        {
            char charAtIdx = s[idx-1];
            dp[idx] = prodUnderMod(2, dp[idx-1]);
            
            if(lastOcc[charAtIdx-'a']!=-1)
            {
                dp[idx] = subUnderMod(dp[idx], dp[lastOcc[charAtIdx-'a']-1]);    
            }
            
            lastOcc[charAtIdx-'a'] = idx;
        }
        
        return dp[s.length()]-1;
    }
};