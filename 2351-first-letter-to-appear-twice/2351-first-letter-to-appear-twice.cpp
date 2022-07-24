class Solution {
public:
    char repeatedCharacter(string s) 
    {
        int freq[26] = {0};
        for(char &ch:s)
        {
            if(++freq[ch-'a']==2)
                return ch;
        }
        return ' ';
    }
};