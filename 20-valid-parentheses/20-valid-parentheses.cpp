class Solution {
public:
    
    bool isValid(string str) 
    {
        if(str.empty())
            return true;
        stack<char> s;
        for(auto i:str)
        {
            if(i=='(' or i=='{' or i=='[')
                s.push(i);
            else
            {
                if(i==')')
                {
                    if(s.empty() or s.top()!='(')
                        return false;
                    s.pop();
                }
                else if(i==']')
                {
                    if(s.empty() or s.top()!='[')
                        return false;
                    s.pop();
                }
                else if(i=='}')
                {
                    if(s.empty() or s.top()!='{')
                        return false;
                    s.pop();
                }
                
            }
        }
        return s.empty();
    }
};