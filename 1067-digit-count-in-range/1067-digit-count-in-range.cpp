class Solution {
private:
    int d;
    string s;
    int memo[11][11][11][2];
public:
    int digitsCount(int d, int low, int high) {
        this->d = d;
        int ans = num_of_digits(high) - num_of_digits(low  - 1);
        return ans;
    }
    
    int num_of_digits(int n){
        if(n == 0) return 0;
        s = to_string(n);
        memset(memo, -1, sizeof(memo));
        int res = 0;
        for(int width = 0; width <= s.size(); width++) res += dfs(0, width, 0, width < s.size());
        return res;
    }
    
    int dfs(int idx, int width, int cnt = 0, bool smaller = false){
        if(idx == width) return cnt;
        if(memo[idx][width][cnt][smaller] >= 0) return memo[idx][width][cnt][smaller];
        int res = 0;
        if(smaller){
            int min_digit = idx == 0 ? 1 : 0;
            for(int digit = min_digit; digit < 10; digit++) res += dfs(idx + 1, width, cnt + (digit == d), true);
        }else{
            int min_digit = idx == 0 ? 1 : 0;
            int max_digit = s[idx] - '0';
            for(int digit = min_digit; digit <= max_digit; digit++) res += dfs(idx + 1, width, cnt + (digit == d), digit < max_digit);
        }
        return memo[idx][width][cnt][smaller] = res;
    }
};