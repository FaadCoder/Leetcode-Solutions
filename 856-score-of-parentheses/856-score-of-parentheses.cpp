class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        int score = 0;
        int lvl = 0;
        for(int idx=0; idx<s.length(); idx++)
        {
            char currentChar = s[idx];
            if(currentChar=='(')
            {
                lvl++;
            }
            else
            {
                lvl--;
                char prevChar = s[idx-1];
                if(prevChar=='(')
                {
                    score += (1<<lvl);
                }
            }
        }
        return score;
    }
};