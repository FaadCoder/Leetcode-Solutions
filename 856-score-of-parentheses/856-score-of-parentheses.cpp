class Solution {
public:
    int scoreOfParentheses(string s) 
    {
        int score = 0;
        int lvl = 0;
        for(int idx=0; idx<s.length(); idx++)
        {
            lvl = lvl + ((s[idx]=='(')?1:-1);
            if(idx>0 and s[idx]==')' and s[idx-1]=='(')
            {
                score += (1<<lvl);
            }
        }
        return score;
    }
};