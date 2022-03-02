class Solution {
    pair<int,int> longestPalindromeHelper(string &s,int i,int j)
    {
        int maxLen = 0;
        while(i>=0 and j<s.length())
        {
            if(s[i]==s[j])
            {
                if(i==j)
                    maxLen++;
                else
                    maxLen+=2;
                i--;
                j++;
            }
            else
                break;
        }
        return {i+1,maxLen};
    }
public:
    string longestPalindrome(string s) 
    {
        if(s.empty())
            return "";
        int startIdx = 0;
        int maxLen = 0;
        for(int i=0;i<s.length();i++)
        {
            auto odd = longestPalindromeHelper(s,i,i);
            auto even = longestPalindromeHelper(s,i,i+1);
            int currLen = max(odd.second,even.second);
            if(currLen>maxLen)
            {
                maxLen = currLen;
                startIdx = (odd.second>even.second)?odd.first:even.first;
            }
        }
        
        return s.substr(startIdx,maxLen);
    }
};