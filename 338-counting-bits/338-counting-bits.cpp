class Solution {
public:
    vector<int> countBits(int n) 
    {
        vector<int> bits(n+1);
        bits[0] = 0;
        for(int i=1;i<=n;i++)
        {
            bits[i] = bits[i/2];
            if(i&1)
                bits[i] += 1;    
        }
        return bits;
    }
};