class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        stack<int> st;
        int j=0;
        for(int ele:pushed)
        {
            st.push(ele);
            while(!st.empty() and st.top()==popped[j])
            {
                st.pop();
                j++;
            }
        }
        return st.empty();
    }
};