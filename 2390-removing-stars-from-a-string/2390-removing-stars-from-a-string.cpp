class Solution {
public:
    string removeStars(string s) {
        string res;
        
        for(char &ch:s)
        {
            if(ch == '*')
                res.pop_back();
            else
                res.push_back(ch);
        }
        
        return res;
    }
};