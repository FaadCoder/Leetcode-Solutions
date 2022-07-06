class Solution {
public:
    vector<long long> maximumEvenSplit(long long n) {
        if(n%2) // odd
            return {};

		vector<long long> ans;
        long long i = 2;
        long long crSum=0;
		
        while((crSum+i)<= n)
        {
            ans.push_back(i);
            crSum+=i;
            i+=2;
        }
		
		// add remaining difference to the last value in answer list
		int sz = ans.size();
        ans[sz-1] += (n-crSum);
        return ans;
    }
};