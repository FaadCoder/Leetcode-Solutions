class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens), end(tokens));
        int start = 0, end = tokens.size() - 1;
        
        int maxScore = 0;
        int currentScore = 0;
        
        while(start <= end)
        {
            if(power >= tokens[start])
            {
                power -= tokens[start++];
                currentScore += 1;
            }
            else if(currentScore > 0)
            {
                currentScore -= 1;
                power += tokens[end--];    
            }
            else
            {
                break;
            }
            
            maxScore = max(maxScore, currentScore);
        }
        
        return maxScore;
    }
};