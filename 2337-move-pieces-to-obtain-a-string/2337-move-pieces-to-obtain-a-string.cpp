class Solution {
public:
    bool canChange(string start, string target) 
    {
        int i =0,j=0;
        while(i<start.length() and j<target.length())
        {
            while(i<start.length() and start[i]=='_')
                i++;
            while(j<target.length() and target[j]=='_')
                j++;
            if(start[i]!=target[j])
                return false;
            if(start[i]=='L' and i<j)
                return false;
            if(start[i]=='R' and i>j)
                return false;
            i++;
            j++;
        }
        while(i<start.length() and start[i]=='_')
            i++;
        while(j<target.length() and target[j]=='_')
                j++;
        return i==j;
    }
};