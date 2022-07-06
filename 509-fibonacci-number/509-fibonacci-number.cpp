class Solution {
public:
    int fib(int n) {
        int a = 0,b = 1,c=0;
        for(int i=1;i<=n;i++)
        {
            c = a+b;
            b=a;
            a=c;
            
        }
        return c;
    }
};