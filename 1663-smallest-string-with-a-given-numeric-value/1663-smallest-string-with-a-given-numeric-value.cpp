class Solution {
public:
    string getSmallestString(int n, int k) 
    {
        string res(n,'a');
        k-=n;
        int i = n-1;
        while(k>0)
        {
            int temp = min(25,k);
            res[i]+=temp;
            k-=temp;
            i--;
        }
        return res;
    }
};