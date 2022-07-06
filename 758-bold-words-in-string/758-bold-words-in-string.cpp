class Solution {
public:
    string boldWords(vector<string>& words, string s) {
        int numberOfWords = (int)size(words);
        int mask[s.length()];
        memset(mask,0,sizeof(mask));
        for(string &word:words)
        {
            int found = (int)s.find(word);
            while(found!=string::npos)
            {
                for(int idx = 0;idx<word.length();idx++)
                    mask[idx+found]=1;
                found = s.find(word,found+1);
            }
        }
        
        string ans;
        bool prev = 0;
        for(int idx=0;idx<s.length();idx++)
        {
            if(mask[idx] and !prev)
            {
                ans+="<b>";
                prev = 1;
            }
            else if(mask[idx]==0 and prev)
            {
                ans += "</b>";
                prev = 0;
            }
            
            ans.push_back(s[idx]);
        }
        if(prev)
            ans+="</b>";
        return ans;
        
    }
};