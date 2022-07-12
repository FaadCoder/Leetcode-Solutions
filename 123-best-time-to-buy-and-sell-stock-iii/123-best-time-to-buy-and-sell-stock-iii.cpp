class Solution {
public:
    int maxProfit(vector<int>& v) {
        if(v.empty()) return 0;
        
        int s0,s1,s2,s3,s4;
        s0=0;
        s1=s2=s3=s4=INT_MIN;
        
        for(int p:v){
            s1=max(s1,s0-p);
            s2=max(s2,s1+p);
            s3=max(s3,s2-p);
            s4=max(s4,s3+p);
        }
        
        return s4;
    }
};