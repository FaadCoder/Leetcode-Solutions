class Solution {
public:
    string removeDuplicateLetters(string s) 
    {
        string result;
        int freq[26] = {0};
        int vis[26] = {0};
        // 1. Count occurrences of each character in the string.
        for(char ch:s)
            freq[ch-'a']++;
        
        // 2. Try to make monotonic increasing string while keeping in mind the freq of each char.
        for(char ch:s)
        {
            freq[ch-'a']--;
            if(vis[ch-'a'])
                continue;
            vis[ch-'a'] = 1;
            while(!result.empty() and ch < result.back() and freq[result.back()-'a']>0)
            {
                vis[result.back()-'a'] = 0;
                result.pop_back();
            }
            result.push_back(ch);
        }
        return result;
    }
};