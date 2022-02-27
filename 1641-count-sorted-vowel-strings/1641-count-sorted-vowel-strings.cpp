class Solution {
    string vowelString = "aeiou";
    
    int dp[51][6];
    
    int getIndexFromChar(char ch)
    {
        int index = 0;
        switch(ch)
        {
            case 'a':
                index = 0;
                break;
            case 'e':
                index = 1;
                break;
            case 'i':
                index = 2;
                break;
            case 'o':
                index = 3;
                break;
            case 'u':
                index = 4;
                break;
            default:
                index = 5;
                break;
        }
        return index;
    }
    
    int countVowelStringsHelper(int n,char prevChar='#')
    {
        if(n==0)
            return 1;
        int indexFromChar = getIndexFromChar(prevChar);
        
        if(dp[n][indexFromChar]!=-1)
            return dp[n][indexFromChar];
        
        int res=0;
        for(char ch:vowelString)
        {
            if(prevChar=='#' or ch>=prevChar)
                res+=countVowelStringsHelper(n-1,ch);
        }
        return dp[n][indexFromChar] = res;
    }
public:
    int countVowelStrings(int n) 
    {
        memset(dp,-1,sizeof(dp));
        return countVowelStringsHelper(n);
    }
};