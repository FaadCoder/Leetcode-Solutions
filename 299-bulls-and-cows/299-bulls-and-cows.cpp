class Solution {
public:
    string getHint(string secret, string guess) {
        int hash[10] = {0};
        
        for(char &ch:secret)
            hash[ch-'0']++;
        
        int bulls = 0;
        int cows = 0;
        
        // step1 : calculate bulls
        for(int idx = 0; idx<guess.length(); idx++)
        {
            char digitInGuess = guess[idx];
            char digitInSecret = secret[idx];
            
            if(digitInGuess == digitInSecret)
            {
                bulls++;
                hash[digitInGuess - '0']--;
            }
        }
        
        // step2: calculate cows
        for(int idx = 0; idx<guess.length(); idx++)
        {
            char digitInGuess = guess[idx];
            char digitInSecret = secret[idx];
            
            if(digitInGuess != digitInSecret and hash[digitInGuess-'0']>0)
            {
                cows++;
                hash[digitInGuess - '0']--;
            }
        }
        
        
        return to_string(bulls)+"A"+to_string(cows)+"B";
    }
};
// Bulls : digits are in correct positions.
// Cows : digits are in wrong positions.