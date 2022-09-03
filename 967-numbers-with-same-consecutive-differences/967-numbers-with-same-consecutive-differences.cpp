class Solution {
    unordered_set<string> vis;
    
    unordered_set<int> visHashSet;
    
    vector<int> ans;
    
    void populateNumsWithString(int n, int k, string temp="")
    {
        if(temp.length() == n and !vis.count(temp))
        {
            if(temp.length() > 1 and temp[0]=='0')
                return;
            vis.insert(temp);
            ans.push_back(stoi(temp));
            return;
        }
        
        for(int num = 0; num <= 9; num++)
        {
            if(temp.empty())
                populateNumsWithString(n, k, temp + to_string(num));
            else
            {
                int prevNum = temp.back() - '0';
                if(abs(prevNum - num) == k)
                    populateNumsWithString(n, k, temp + to_string(num));
            }
        }
    }
    
public:
    vector<int> numsSameConsecDiff(int N, int K) {
        vector<int> cur = {1, 2, 3, 4, 5, 6, 7, 8, 9};
        for (int i = 2; i <= N; ++i) {
            vector<int> cur2;
            for (int x : cur) {
                int y = x % 10;
                if (y + K < 10)
                    cur2.push_back(x * 10 + y + K);
                if (K > 0 && y - K >= 0)
                    cur2.push_back(x * 10 + y - K);
            }
            cur = cur2;
        }
        return cur;
    }
};