class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n = arr.size();
        double l = 0, r = 1.0;
        while(l<r){
            double m = (l+r)/2;
			//max_f is used to store the maximum fraction less than mid
            double max_f = 0.0;
			//p and q are used for storing the indices of max fraction
            int total=0,p=0,q=0;
            int j=1;
            for(int i=0;i<n-1;i++){
			//if this fraction is greater than mid , move denominator rightwards to find a smaller mid
                while(j<n && arr[i] > m*arr[j])
                    j++;
					//j elements are greater than mid in this row , n-j are smaller , add them to result
                total += (n-j);
                if(j==n)
                    break;
				//cast to double speedily
                double f = static_cast<double>(arr[i]) / arr[j];
				//update max fraction for this mid
                if (f > max_f) {
                  p = i;
                  q = j;
                  max_f = f;
                }
            }
            if (total == k)
                return {arr[p], arr[q]};       
			//there are too many fractions less than mid=> mid is too big => make mid smaller and try
            else if (total > k)
                r = m;
            else
                l = m;
        }
        return {};
    }
};