class Solution {
public:
    bool isSubsequence(string s, string t) 
    {
        int i=0;
        int j=0;
        while(i<s.length() and j<t.length())
        {
            if(s[i]==t[j])
            {
                i++;
                j++;
            }
            else
            {
                j++;
            }
            if(i==s.length())
                break;
        }
        return i==s.length();
    }
};