class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        
        int st = 0;
        int longestLength = 0;
        
        for(int en = 0; en<s.length(); en++)
        {
            mp[s[en]]++;
            while(mp[s[en]]>1)
            {
                mp[s[st]]--;
                if(mp[s[st]]<=0)
                    mp.erase(s[st]);
                st++;
            }
            longestLength = max(longestLength,en-st+1);
        }
        
        return longestLength;
    }
};