class Solution {
public:
    int dp[1000000]; // array for memoization
    int getKth(int lo, int hi, int k) {
        memset(dp, -1, sizeof(dp)); // initializing the array with -1
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; // prority_queue (min heap)
        for(int i=lo; i<=hi; i++){
            int p = power(i); // recursive function to calculate the power of each element within the range [lo, hi].
            pq.push(make_pair(p, i)); // storing each element with its power in pairs within the pq
        }
        while(--k){
            pq.pop(); // removing all elements that comes before the kth element in [lo, hi]. 
        }
        return pq.top().second; // returning the kth element
    }
    
    int power(int i){
        if(dp[i] != -1) return dp[i]; // if power of ith element is already known, simply return dp[i]
        if(i == 1) return 0; // since, for 1 -> 1, steps = 0 
        int cnt = 0; // counter to count the number of steps
        if(i & 1){ // if i is odd call power(3*i+1)
            cnt = 1 + power(3*i+1);
        }else{ // if i is even call power(i/2)
            cnt = 1 + power(i/2);
        }
        return dp[i] = cnt; // store the power of ith element in dp[i], *Note: this is where memoization is done*
    }
};