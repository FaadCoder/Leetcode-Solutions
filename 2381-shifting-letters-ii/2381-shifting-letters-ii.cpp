class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        unordered_map<int, int> mp;
        
        for(auto shift : shifts)
        {
            mp[shift[0]] += shift[2] ? 1 : -1;
            mp[shift[1] + 1] += shift[2] ? -1 : 1;
        }
        
        for(int i = 1; i<s.length(); i++)
            mp[i] += mp[i-1];
        
        for(int i=0;i<s.length(); i++)
            s[i] = ((s[i]-'a' + mp[i])%26 + 26)%26 + 'a';
        
        return s;
    }
};