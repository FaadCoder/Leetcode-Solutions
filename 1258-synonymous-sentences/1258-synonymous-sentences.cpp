class Solution
{
    public:
    unordered_map<string, string> uf;
    unordered_map<string, unordered_set < string>> mp;
    vector<string> generateSentences(vector<vector < string>> &synonyms, string text)
    {
        for (auto &s: synonyms)
        {
            mp[s[0]].insert(s[0]);
            mp[s[1]].insert(s[1]);

           	// Union find
            string s1 = find(s[0]);
            string s2 = find(s[1]);
            if (s1 != s2)
            {
               	// union them to the smallest lexicographical string
               	// And put all the synonyms to the map of that string
                if (s1 < s2)
                {
                    uf[s2] = s1;
                    mp[s1].insert(mp[s2].begin(), mp[s2].end());
                }
                else
                {
                    uf[s1] = s2;
                    mp[s2].insert(mp[s1].begin(), mp[s1].end());
                }
            }
        }

       	// Get all the words separated by space
        istringstream ss(text);
        vector<string> input;
        string in = "";
        while (ss >> in)
            input.push_back(in);

       	// Backtracking
        vector<string> res;
        helper(input, 0, input.size(), "", res);

       	// Sort
        sort(res.begin(), res.end());
        return res;
    }

    void helper(vector<string> &input, int i, int n, string sofar, vector<string> &res)
    {
        if (i == n)
        {
            res.push_back(sofar.substr(1));
            return;
        }

        string s = input[i];
        if (uf.count(s))
        {
            for (auto &syn: mp[find(s)])
            {
                helper(input, i + 1, n, sofar + " " + syn, res);
            }
        }
        else
        {
            helper(input, i + 1, n, sofar + " " + s, res);
        }
    }

    string find(string s)
    {
        if (!uf.count(s))
            uf[s] = s;
        else if (uf[s] != s)
            uf[s] = find(uf[s]);
        return uf[s];
    }
};