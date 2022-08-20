class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int minOps = blocks.length();
        
        int whiteBlocks = 0;
        
        for(int block = 0; block < blocks.length(); block++)
        {
            whiteBlocks += (blocks[block]=='W');
            
            if(block >= k)
                whiteBlocks -= (blocks[block - k] == 'W');
            
            if(block >= k - 1)
                minOps = min(minOps, whiteBlocks);
        }
        
        return minOps;
    }
};