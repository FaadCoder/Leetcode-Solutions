class Solution {
public:
    string reorderSpaces(string text) {
        int totalLength = text.length();
        int wordLength = 0;
        stringstream ss(text);
        string word;
        
        vector<string> words;
        while(ss>>word)
        {
            wordLength += word.length();
            words.push_back(word);
        }
        
        int totalSpaces = totalLength - wordLength;
        int totalPlaces = words.size() - 1;
        
        if(totalPlaces == 0)
            return words[0]+string(totalSpaces,' ');
        
        int spaceBetweenWords = totalSpaces/totalPlaces;
        int extraSpaces = totalSpaces % totalPlaces;
        
        string ans;
        
        for(int idx=0; idx<words.size(); idx++)
        {
            ans+=words[idx];
            if(idx==words.size()-1)
                break;
            for(int space = 1; space<=spaceBetweenWords; space++)
                ans.push_back(' ');
            
        }
        while(extraSpaces>0)
        {
            ans.push_back(' ');
            extraSpaces--;
        }
        return ans;
    }
};