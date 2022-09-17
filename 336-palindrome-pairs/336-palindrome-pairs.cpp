class Solution {
public:
    struct Trie {
        Trie* nodes[26];
        vector<int> palin;
        vector<int> end;
    };
    vector<vector<int>> palindromePairs(vector<string>& words) {
        auto checkPalindrome = [&](string s, int dir){ // O(K) palindrome check for all prefix / suffix in 1 pass
            long long forward = 0, backward = 0, p = 101, M = 1e9+7, f = 1, n = size(s);
            vector<bool> ok(n);
            for (int j = dir==1?0:n-1; ~j && j < n; j += dir){
                int c = s[j] - 'a' + 1;
                forward += f * c % M;
                backward = p * backward + c;
                f = f * p % M;
                backward %= M;
                forward %= M;
                ok[j] = backward == forward; // forward and backward hash must equal for it to be a palindrome.
            }
            return ok;
        };
        
        Trie* root = new Trie();
        for (int i = 0; i < words.size(); ++i){
            vector<bool> ok = checkPalindrome(words[i], 1); // prefix
            Trie* cur = root;
            for (int j = (int)size(words[i])-1; ~j; --j){ // store words into Trie
                if (!cur->nodes[words[i][j]-'a']){
                    cur->nodes[words[i][j]-'a']=new Trie();
                }
                if (ok[j]){ // prefix is a palindrome, so store it
                    cur->palin.push_back(i);
                }
                cur = cur->nodes[words[i][j]-'a'];
            }
            cur->end.push_back(i);
        }
        
        vector<vector<int>> ans;
        for (int i = 0; i < size(words); ++i){
            vector<bool> ok = checkPalindrome(words[i], -1); // suffix
            Trie* cur = root;
            for (int j = 0; j < size(words[i]) && cur; ++j){
                if (ok[j]) for (int e : cur->end){ // case 1, len of A > len of B
                    ans.push_back({i, e});
                }
                cur = cur->nodes[words[i][j]-'a'];
            }
            if (cur) for (int j : cur->palin){ // case 2, len of A < len of B
                ans.push_back({i, j});
            }
            if (cur) for (int j : cur->end) if (i != j){ // case 3, len of A = len of B
                ans.push_back({i, j});
            }
        }
        return ans;
    }
};