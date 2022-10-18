class Solution {
public:
    string countAndSay(int n) {
        if(n==1)
            return "1";
        
        string previous = countAndSay(n-1);
        string current;
        int counter = 1;
        
        for(int idx = 1; idx < previous.length(); idx++)
        {
            if(previous[idx - 1] == previous[idx])
            {
                counter+=1;
            }
            else
            {
                current += to_string(counter);
                current.push_back(previous[idx-1]);
                counter = 1;
            }
        }
        current += to_string(counter);
        current.push_back(previous.back());
        return current;
    }
};