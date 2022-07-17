class Solution
{

    int getMinimumTransactions(int idx, vector<int> &balance)
    {
        if (idx >= balance.size())
            return 0;
        if (balance[idx] == 0)
            return getMinimumTransactions(idx + 1, balance);
        int currentBalance = balance[idx];
        int res = INT_MAX / 2;

        for (int i = idx + 1; i < balance.size(); i++)
        {
            int nextBalance = balance[i];
            if (currentBalance * nextBalance < 0)
            {
                balance[i] += currentBalance;
                res = min(res, 1 + getMinimumTransactions(idx + 1, balance));
                balance[i] -= currentBalance;
            }
        }
        return res;
    }

    public:
        int minTransfers(vector<vector < int>> &transactions)
        {
            unordered_map<int, int> currentBalance;
            for (auto &transaction: transactions)
            {
                currentBalance[transaction[0]] -= transaction[2];
                currentBalance[transaction[1]] += transaction[2];
            }
            vector<int> balance;
            for (auto it: currentBalance)
                balance.push_back(it.second);

            return getMinimumTransactions(0, balance);
        }
};