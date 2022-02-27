class Solution {
public:
    #define ll unsigned long long int
    int widthOfBinaryTree(TreeNode* root) {
        if(!root)
            return 0;
        queue<pair<TreeNode *,ll>> q;
        q.push({root,1});
        ll mx=0;
        while(!q.empty())
        {
            ll sz=q.size();
            ll first = q.front().second;
            ll last = first;
            while(sz--)
            {
                auto front = q.front();
                q.pop();
                last = front.second;
                if(front.first->left)
                    q.push({front.first->left,2*last});
                if(front.first->right)
                    q.push({front.first->right,2*last+1});
                
            }
            
            mx=max(mx,last-first+1);
              
        }
        return mx;
    }
};