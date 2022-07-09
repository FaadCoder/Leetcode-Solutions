class Solution {
    unordered_set<string> hash;
public:
    bool differByOne(vector<string>& d) {
    int mod = 1000000007, n = d.size(), m = d[0].size();
    vector<int> hash(n);
    for (auto i = 0; i < n; ++i)
        for (auto j = 0; j < m; ++j)
            hash[i] = (26l * hash[i] + (d[i][j] - 'a')) % mod;
    for (int j = m - 1, mult = 1; j >= 0; --j) {
        unordered_map<int, vector<int>> m;
        for (auto i = 0; i < n; ++i) {
            int h = (mod + hash[i] - (long)mult * (d[i][j] - 'a') % mod) % mod;
            auto it = m.find(h);
            if (it != end(m))
                for (int pi : it->second)
                    if (equal(begin(d[i]), begin(d[i]) + j, begin(d[pi])) 
                       && equal(begin(d[i]) + j + 1, end(d[i]), begin(d[pi]) + j + 1))
                        return true;
            m[h].push_back(i);
        }
        mult = 26l * mult % mod;
    }
    return false;
}
};