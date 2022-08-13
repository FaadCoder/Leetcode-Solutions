class Solution {
public:
    int kthGrammar(int n, int k) {
        if(k==1)
            return 0;
        if(n==1)
            return 0;
        
        int symbols = (1<<(n-1));
        int kthSymbol = 0;
        if(k<=(symbols/2))
            kthSymbol = kthGrammar(n-1, k);
        else
            kthSymbol = !kthGrammar(n-1, k - (symbols>>1));
        return kthSymbol;
    }
};