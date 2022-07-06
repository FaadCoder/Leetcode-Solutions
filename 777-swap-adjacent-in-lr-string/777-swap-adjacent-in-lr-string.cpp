class Solution {
public:
    bool canTransform(string start, string end) {
        int idx1 = 0;
        int idx2 = 0;
        while(idx1<start.length() and idx2<end.length())
        {
            while(idx1<start.length() and start[idx1]=='X')
                idx1++;
            while(idx2<end.length() and end[idx2]=='X')
                idx2++;
            
            if(idx1==start.length() and idx2==end.length())
                return true;
            
            if(idx1==start.length() or idx2==end.length())
                break;
            
            if(start[idx1]!=end[idx2])
                return false;
            
            if(start[idx1]=='R' and idx1>idx2)
                return false;
            
            if(start[idx1]=='L' and idx1<idx2)
                return false;
            idx1++;
            idx2++;
        }
        while(idx1<start.length() and start[idx1]=='X')
                idx1++;
        while(idx2<end.length() and end[idx2]=='X')
                idx2++;
        return idx1==idx2;
    }
};