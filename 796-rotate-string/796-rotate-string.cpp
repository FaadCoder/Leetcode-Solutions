class Solution {
public:
    bool rotateString(string s, string goal) 
    {
        return (s.length()==goal.length() and (s+s).find(goal)!=string::npos);      
    }
};