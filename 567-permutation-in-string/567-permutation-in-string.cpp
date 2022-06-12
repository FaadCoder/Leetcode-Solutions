class Solution {
    bool areHashSame(int *h1,int *h2)
    {
        for(int i=0;i<26;i++)
        {
            if(h1[i]!=h2[i])
                return false;
        }
        return true;
    }
    
public:
    bool checkInclusion(string s1, string s2)
    {
        if(s1.length() > s2.length())
            return false;
        int hashOfStringS1[26] = {0};
        int hashOfStringS2[26] = {0};
        for(char ch:s1)
            hashOfStringS1[ch-'a']++;
        for(int idx = 0; idx<s2.length(); idx++)
        {
            if(idx>=s1.length())
            {
                if(areHashSame(hashOfStringS2,hashOfStringS1))
                    return true;
                hashOfStringS2[s2[idx - s1.length()]-'a']--;
                hashOfStringS2[s2[idx]-'a']++;
            }
            else
            {
               hashOfStringS2[s2[idx]-'a']++; 
            }
        }
        return areHashSame(hashOfStringS2,hashOfStringS1);
    }
};


