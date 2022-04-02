class Solution {
public:
    bool validPalindrome(string s) {
        return valid(s, 0, s.length() - 1, 1);
    }

private:
    bool valid(string& s, int i, int j, int d) { // d: num of chars you can delete at most
        return i >= j || (s[i] == s[j] ? valid(s, i + 1, j - 1, d) : d > 0 && (valid(s, i + 1, j, d - 1) || valid(s, i, j - 1, d - 1)));
    }
};