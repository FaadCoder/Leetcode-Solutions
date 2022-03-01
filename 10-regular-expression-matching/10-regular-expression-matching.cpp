class Solution {
public:
    bool isMatch(string s, string p) 
    {
        int stringLen = s.length();
        int patternLen = p.length();
        bool matchDP[patternLen+1][stringLen+1];
        memset(matchDP,false,sizeof(matchDP));
        
        for(int i=0;i<=patternLen;i++)
        {
            for(int j=0;j<=stringLen;j++)
            {
                if(i==0 and j==0)
                {
                    matchDP[i][j] = true;
                }
                else if(i==0)
                {
                    matchDP[i][j] = false;
                }
                else if(j==0)
                {
                    if(p[i-1]=='*')
                    {
                        matchDP[i][j] = matchDP[i-2][j];
                    }
                    else
                    {
                        matchDP[i][j] = false;
                    }
                }
                else
                {
                    char patternChar = p[i-1];
                    char stringChar = s[j-1];
                    if(patternChar=='*')
                    {
                        matchDP[i][j] = matchDP[i-2][j];
                        if(p[i-2]==s[j-1] or p[i-2]=='.')
                        {
                            matchDP[i][j] = matchDP[i][j] or matchDP[i][j-1];
                        }
                    }
                    else
                    {
                        if(patternChar==stringChar)
                        {
                            matchDP[i][j] = matchDP[i-1][j-1];
                        }
                        else if(patternChar == '.')
                        {
                            matchDP[i][j] = matchDP[i-1][j-1];
                        }
                        else
                        {
                            matchDP[i][j] = false;
                        }
                    }
                }
            }
        }
        return matchDP[patternLen][stringLen];
    }
};