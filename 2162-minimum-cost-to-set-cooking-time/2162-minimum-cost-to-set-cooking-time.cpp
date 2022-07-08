class Solution {
public:
    int minCostSetTime(int startAt, int moveCost, int pushCost, int targetSeconds) {
    auto cost = [&](int pos, int m, int s){
        if (min(m, s) < 0 || max(m, s) > 99)
            return INT_MAX;
        int res = 0;
        for (auto digit : to_string(m * 100 + s)) {
            res += pushCost + (pos == digit - '0' ? 0 : moveCost);
            pos = digit - '0';
        }
        return res;
    };
    int m = targetSeconds / 60, s = targetSeconds % 60;
    return min(cost(startAt, m, s), cost(startAt, m - 1, s + 60));
}
};