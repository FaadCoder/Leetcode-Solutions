class Solution {
public:
    uint32_t reverseBits(uint32_t n) {
        uint32_t ans = 0;
        
        for(int bit = 0; bit < 32; bit+=1)
        {
            int bitToUse = ((1<<bit) & n) > 0 ? 1 : 0;
            if(bitToUse)
                ans |= (1<<(32-bit-1));
            
        }
        return ans;
    }
};