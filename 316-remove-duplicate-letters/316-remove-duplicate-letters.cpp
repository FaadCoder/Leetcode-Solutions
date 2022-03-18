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
            
            // Don't use the same character again (As mentioned in the constraints)
            if(vis[ch-'a'])
                continue;
            
            // Mark the used character visited.
            vis[ch-'a'] = 1;
            
            // Try to make monotonic increasing string.
            while(!result.empty() and ch < result.back() and freq[result.back()-'a'] > 0)
            {   
                // Mark the removed character UnVisited.
                vis[result.back()-'a'] = 0;
                
                // Remove the character.
                result.pop_back();
            }
            
            // At this point we are sure that the string is monotonic,
            // so add the character in the resultant string.
            result.push_back(ch);
        }
        return result;
    }
};