class Solution {
private:
    long res, n;
    vector<long> nums;
    map<int, int> mp;
public:
    void bt(long val, long rot, long dec) {
        if (val != rot && val <= n) {
            res++;
        }
        for (auto& num : nums) {
            if (val*10 + num > n) break;
            bt(val*10+num, mp[num]*dec + rot, dec*10);
        }
    }
    
    int confusingNumberII(int N) {
        res = 0; n = N;
        nums = {0, 1, 6, 8, 9};
        mp[0] = 0; mp[1] = 1; mp[6] = 9; mp[8] = 8; mp[9] = 6;
        for (int i = 1; i < 5; i++) {
            bt(nums[i], mp[nums[i]], 10);
        }
        return res;
    }
};