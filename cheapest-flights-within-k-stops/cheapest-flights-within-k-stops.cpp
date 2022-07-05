class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        if (src == dst) {
            return 0;
        }

        vector<int> previous(n, INT_MAX);
        vector<int> current(n, INT_MAX);
        previous[src] = 0;
        for (int i = 1; i < k + 2; i++) {
            current[src] = 0;
            for (vector<int>& flight : flights) {
                int previous_flight = flight[0];
                int current_flight = flight[1];
                int cost = flight[2];

                if (previous[previous_flight] < INT_MAX) {
                    current[current_flight] = min(current[current_flight],
                                                  previous[previous_flight] + cost);
                }
            }
            previous.assign(current.begin(), current.end());
        }
        return current[dst] == INT_MAX ? -1 : current[dst];
    }
};