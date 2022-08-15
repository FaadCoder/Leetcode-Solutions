class SparseVector {
    
public:
    
    unordered_map<int,int> idxToNumHashMap;
    
    SparseVector(vector<int> &nums) {
        
        for(int idx = 0; idx < nums.size(); idx++)
        {
            if(nums[idx]!=0)
                idxToNumHashMap[idx] = nums[idx];
        }
        
    }
    
    // Return the dotProduct of two sparse vectors
    int dotProduct(SparseVector& vec) {
        int dotProd = 0;
        
        for(auto it:vec.idxToNumHashMap)
        {
            int idx = it.first;
            if(idxToNumHashMap.count(idx))
                dotProd += it.second * idxToNumHashMap[idx];
        }
        
        return dotProd;
    }
};

// Your SparseVector object will be instantiated and called as such:
// SparseVector v1(nums1);
// SparseVector v2(nums2);
// int ans = v1.dotProduct(v2);