class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> cnt(10);
        for (char c: num) {
            cnt[c - '0']++;
        }
        
        string res1, res2;
        for (int i: num) {
            for (int j = 9; j >= 0; j--)  {
                if (cnt[j] > 1 && (j > 0 || res1.size())) {
                    res1.push_back('0' + j);
                    res2.push_back('0' + j);
                    cnt[j] -= 2;
                    break;
                }
            }
        }
        for (int i = 9; i >= 0; i--) {
            if (cnt[i]) {
                res1 += '0' + i; break;
            }
        }
        reverse(begin(res2), end(res2));
        return res1 + res2;
    }
};