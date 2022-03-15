class Solution {
public:
    string minRemoveToMakeValid(string s) 
    {
        int len = 0;
        int left=0,right=0;
        unordered_map<int,int> vis;
        for(int i=0;i<s.length();i++)
        {
            if(s[i]=='(')
                left++;
            else if(s[i]==')')
                right++;
            if(right>left)
            {
                vis[i]++;
                left = right = 0;
            }
        }
        left = right = 0;
        for(int i=s.length()-1;i>=0;i--)
        {
            if(s[i]=='(')
                left++;
            else if(s[i]==')')
                right++;
            if(right<left)
            {
                vis[i]++;
                left = right = 0;
            }
        }
        string str;
        for(int i=0;i<s.length();i++)
        {
            if(vis.count(i))
                continue;
            str.push_back(s[i]);
        }
        return str;
    }
};