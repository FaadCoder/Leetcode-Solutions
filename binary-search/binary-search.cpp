class Solution {
public:
    int search(vector<int>& nums, int target) {
        auto it = lower_bound(begin(nums),end(nums),target);
        if(it==nums.end())
            return -1;
        return *it==target?it-nums.begin():-1;
    }
};