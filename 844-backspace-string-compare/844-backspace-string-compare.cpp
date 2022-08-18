class Solution {
    
    string getString(string &str)
    {
        string ans;
        
        int back = 0;
        
        for(int idx = str.length()-1; idx>=0; idx--)
        {
            if(str[idx]=='#')
                back += 1;
            else
            {
                if(back > 0)
                {
                    back -= 1;
                    if(back < 0)
                        back = 0;
                }
                else
                    ans.push_back(str[idx]);
                
            }
        }
        // cout<<str<<" "<<ans<<endl;
        return ans;
    }
    
public:
    bool backspaceCompare(string s, string t) {
        return (getString(s) == getString(t));
    }
};