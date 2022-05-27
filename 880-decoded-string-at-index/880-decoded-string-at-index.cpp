class Solution
{
    public:
        string decodeAtIndex(string s, int k)
        {
            long long int letterCount = 0;
            for (char &ch: s)
            {
                if (isdigit(ch))
                {
                    letterCount *= (ch - '0');
                }
                else
                {
                    ++letterCount;
                }
            }
            int stringSize = s.length();
            for (int idx = stringSize - 1; idx >= 0; --idx) 
            {
                k%=letterCount;
                if(k==0 and !isdigit(s[idx]))
                    return (string)""+s[idx];
                if(isdigit(s[idx]))
                    letterCount /= (s[idx]-'0');
                else
                    letterCount-=1;
            }
            return "";
        }
};