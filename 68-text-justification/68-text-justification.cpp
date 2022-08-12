class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> justifiedText;
        
        int start = 0;
        while(start < words.size())
        {
            int wordsCount = words[start].length();
            int end = start + 1;
            int space = 0;
            
            while(end < words.size() and wordsCount + space + words[end].length() + 1 <= maxWidth)
            {
                wordsCount += words[end].length();
                space += 1;
                end++;
            }
            
            int totalSpaces = maxWidth - wordsCount;
            int minSpace = (space == 0) ? 0 : totalSpaces / space;
            int extraSpace = (space == 0) ? 0 : totalSpaces % space;
            
            if(end == words.size())
                minSpace = 1, extraSpace = 0;
            
            string currentString;
            
            for(int idx = start; idx<end; idx++)
            {
                currentString += words[idx];
                
                if(idx == end - 1)
                    break;
                
                for(int s = 0; s<minSpace; s++)
                    currentString += " ";
                
                if(extraSpace > 0)
                    currentString += " ", extraSpace-=1;
                
            }
            
            while(currentString.length() < maxWidth)
                currentString.push_back(' ');
            
            justifiedText.push_back(currentString);
            
            start = end;
            
        }
        
        return justifiedText;
    }
};