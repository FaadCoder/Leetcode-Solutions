struct Node{
    Node *left,*right;
    int count;
    Node()
    {
        left = right = NULL;
        count = 0;
    }
};


class Trie{
private:
    Node *root;
    
    int getCount(Node *node)
    {
        return (!node)?0:node->count;
    }
    
    int queryHelper(int val,int limit,int bitIdx,Node *node)
    {
        if(!node)
            return 0;
        if(bitIdx == -1)
            return node->count;
        int valIdx = (val & (1<<bitIdx))>0?1:0;
        int limitIdx = (limit & (1<<bitIdx))>0?1:0;
        if(valIdx == 0)
        {
            if(limitIdx==0)
            {
                return queryHelper(val,limit,bitIdx-1,node->left);
            }
            else
            {
                return getCount(node->left) + queryHelper(val,limit,bitIdx-1,node->right);
            }
        }
        else
        {
            if(limitIdx == 0)
            {
                return queryHelper(val,limit,bitIdx-1,node->right);
            }
            else
            {
               return getCount(node->right) + queryHelper(val,limit,bitIdx-1,node->left); 
            }
        }
    }
    
public:  
    Trie()
    {
        root = new Node();
    }

    void insert(int val,int maxBits)
    {
        Node *temp = root;
        for(int bit = maxBits; bit>=0; bit--)
        {
            int valIdx = (val & (1<<bit))>0?1:0;
            if(valIdx==0)
            {
                if(!temp->left)
                    temp->left = new Node();
                temp = temp->left;
            }
            else
            {
                if(!temp->right)
                    temp->right = new Node();
                temp = temp->right;
            }
            temp->count++;
        }
        
    }
    
    int query(int val,int limit,int bitIdx)
    {
        return queryHelper(val,limit,bitIdx,root);
    }
  
};

class Solution {
public:
    int countPairs(vector<int>& nums, int low, int high) 
    {
        int maxBits = 14;
        int pairsCount = 0;
        Trie trie;
        for(int num:nums)
        {
            pairsCount += trie.query(num,high,maxBits);
            pairsCount -= trie.query(num,low-1,maxBits);
            trie.insert(num,maxBits);
        }
        return pairsCount;
    }
};






