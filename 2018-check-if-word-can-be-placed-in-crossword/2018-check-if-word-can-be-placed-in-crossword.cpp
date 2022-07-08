class Solution {
    bool same(vector<char> &A, int first, int last, string &s) { // returns true if `A[first..last]` equals `s` or reversed `s`.
        if (last - first + 1 != s.size()) return false;
        int i = 0, N = s.size();
        while (i < N && (A[first + i] == ' ' || A[first + i] == s[i])) ++i; // match from left to right
        if (i == N) return true;
        for (i = 0; i < N && (A[last - i] == ' ' || A[last - i] == s[i]);) ++i; // match from right to left
        return i == N;
    }
    bool match(vector<vector<char>> &A, string s) { // returns `true` if matrix `A` matches string `s` horizontally
        int N = A[0].size();
        for (auto &row : A) {
            for (int i = 0; i < N; ) {
                while (i < N && row[i] == '#') ++i;
                int start = i;
                while (i < N && row[i] != '#') ++i;
                if (same(row, start, i - 1, s)) return true; // match `row[start..(i-1)]` with `s`.
            }
        }
        return false;
    }
public:
    bool placeWordInCrossword(vector<vector<char>>& A, string s) {
        int M = A.size(), N = A[0].size();
        vector<vector<char>> B(N, vector<char>(M)); // `B` is the transpose of `A`
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++ j) {
                B[j][i] = A[i][j];
            }
        }
        return match(A, s) || match(B, s);
    }
};