class Solution {
    
    vector<string> morseCode = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> uniqueTransformations;
        
        for(string &word:words)
        {
            string transformation;
            for(char &ch:word)
                transformation += morseCode[ch-'a'];
            
            uniqueTransformations.insert(transformation);
        }
        
        return (int)uniqueTransformations.size();
    }
};