class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        if(next_permutation(nums.begin(),nums.end()))
            return;
        sort(nums.begin(),nums.end());
    }
};