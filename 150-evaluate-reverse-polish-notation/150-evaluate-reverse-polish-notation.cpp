class Solution {
    
    
    bool isOperator(string &str)
    {
        return (str=="+" or str == "-" or str == "*" or str == "/");
    }
    
    int getExpressionResult(int a,int b, string &oper)
    {
        int res;
        if(oper == "+")
        {
            res = a + b;
        }
        else if(oper == "-")
        {
            res = a-b;
        }
        else if(oper == "*")
        {
            res = a*b;
        }
        else
        {
            res = a/b;
        }
        return res;
    }
    
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> q;
        for(string &token:tokens)
        {
            if(isOperator(token))
            {
                int second = q.top();
                q.pop();
                int first = q.top();
                q.pop();
                q.push(getExpressionResult(first,second,token));
            }
            else
            {
                q.push(stoi(token));
            }
        }
        return q.top();
    }
};