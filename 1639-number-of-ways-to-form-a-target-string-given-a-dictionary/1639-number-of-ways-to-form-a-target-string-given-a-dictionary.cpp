class Solution {
    const int MOD = 1e9+7;
    vector<vector<int>> freq;
    vector<vector<int>> dp;
    
    int addUnderMod(int a, int b)
    {
        return (a%MOD + b%MOD) %MOD;
    }
    
    int prodUnderMod(int a,int b)
    {
        return ((long long)a%MOD * (long long)b%MOD) %MOD;
    }
    
    int getTotalWays(vector<string> &words,string &target,int targetItr=0,int wordItr=0)
    {
        if(targetItr>=target.length())
            return 1;
        
        if(wordItr>=words.front().length())
            return 0;
        if(dp[targetItr][wordItr]!=-1)
            return dp[targetItr][wordItr];
        
        return dp[targetItr][wordItr] = addUnderMod(getTotalWays(words,target,targetItr,wordItr+1), 
                                                    prodUnderMod(getTotalWays(words,target,targetItr+1,wordItr+1), freq[wordItr][target[targetItr]-'a']));
        
    }
    
public:
    int numWays(vector<string>& words, string target) {
        dp.resize(target.length()+1,vector<int>(words[0].length()+1,-1));
        freq.resize(words[0].length(),vector<int>(26,0));
        
        for(string &word:words)
        {
            for(int idx=0; idx<word.length();idx++)
                freq[idx][word[idx]-'a']++;
        }
        return getTotalWays(words,target);
    }
};