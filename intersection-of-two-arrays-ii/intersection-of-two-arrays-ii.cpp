class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() > nums2.size()) {
        return intersect(nums2, nums1);
    }
    unordered_map<int, int> m;
    for (auto n : nums1) {
        ++m[n];
    }
    int k = 0;
    for (auto n : nums2) {
        auto it = m.find(n);
        if (it != end(m) && --it->second >= 0) {
            nums1[k++] = n;
        }
    }
    return vector(begin(nums1), begin(nums1) + k);
}
};