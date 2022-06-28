class Solution
{
    unordered_map< string,
        function < int(int, int) > > hashMap = {
		{
                "+",
               [](int a, int b)
                {
                    return a + b;
                }
            },
            {
                "-",
               [](int a, int b)
                {
                    return a - b;
                }
            },
            {
                "*",
               [](int a, int b)
                {
                    return a * b;
                }
            },
            {
                "/",
               [](int a, int b)
                {
                    return a / b;
                }
            },
        };

    public:
        int evalRPN(vector<string> &tokens)
        {
            stack<int> q;
            for (string &token: tokens)
            {
                const auto &it = hashMap.find(token);
                if (it != hashMap.end())
                {
                    int rhs = q.top();
                    q.pop();
                    int lhs = q.top();
                    q.pop();
                    q.push(it->second(lhs, rhs));
                }
                else
                {
                    q.push(stoi(token));
                }
            }
            return q.top();
        }
};