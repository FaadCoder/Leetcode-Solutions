class Solution {
public:
    bool isMajorityElement(vector<int>& nums, int target) {
        auto lowerBound = lower_bound(begin(nums),end(nums),target);
        if(lowerBound==end(nums) or *lowerBound!=target)
            return false;
        auto upperBound = upper_bound(begin(nums),end(nums),target);
        
        int totalOccurrence = (upperBound-begin(nums)) - (lowerBound-begin(nums));
        return totalOccurrence > size(nums)/2;
    }
};