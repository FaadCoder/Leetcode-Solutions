class Solution {
public:
    string pushDominoes(string A) {
        int N = A.length();
        vector<int> forces(N, 0);

     
        int force = 0;
        for (int i = 0; i < N; ++i) {
            if (A[i] == 'R') force = N;
            else if (A[i] == 'L') force = 0;
            else force = max(force - 1, 0);
            forces[i] += force;
        }

        force = 0;
        for (int i = N-1; i >= 0; --i) {
            if (A[i] == 'L') force = N;
            else if (A[i] == 'R') force = 0;
            else force = max(force - 1, 0);
            forces[i] -= force;
        }

        string ans;
        for (int f: forces)
            ans.push_back(f > 0 ? 'R' : f < 0 ? 'L' : '.');
        return ans;
    }
};