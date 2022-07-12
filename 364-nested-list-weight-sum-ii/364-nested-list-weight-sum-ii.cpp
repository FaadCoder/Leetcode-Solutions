/**
 * // This is the interface that allows for creating nested lists.
 * // You should not implement it, or speculate about its implementation
 * class NestedInteger {
 *   public:
 *     // Constructor initializes an empty nested list.
 *     NestedInteger();
 *
 *     // Constructor initializes a single integer.
 *     NestedInteger(int value);
 *
 *     // Return true if this NestedInteger holds a single integer, rather than a nested list.
 *     bool isInteger() const;
 *
 *     // Return the single integer that this NestedInteger holds, if it holds a single integer
 *     // The result is undefined if this NestedInteger holds a nested list
 *     int getInteger() const;
 *
 *     // Set this NestedInteger to hold a single integer.
 *     void setInteger(int value);
 *
 *     // Set this NestedInteger to hold a nested list and adds a nested integer to it.
 *     void add(const NestedInteger &ni);
 *
 *     // Return the nested list that this NestedInteger holds, if it holds a nested list
 *     // The result is undefined if this NestedInteger holds a single integer
 *     const vector<NestedInteger> &getList() const;
 * };
 */
class Solution {
    int getSum(vector<NestedInteger>& nestedList,int sum=0)
    {
        int weightedSum = 0;
        int levelSum = 0;
        queue<NestedInteger> bfsQueue;
        for(NestedInteger &nestedInteger:nestedList)
            bfsQueue.push(nestedInteger);
        
        while(!bfsQueue.empty())
        {
            int size = bfsQueue.size();
            
            while(size-- > 0)
            {
                auto front = bfsQueue.front();
                bfsQueue.pop();
                if(front.isInteger())
                    levelSum += front.getInteger();
                else
                {
                    for(NestedInteger &nestedInteger:front.getList())
                        bfsQueue.push(nestedInteger);
                }
                
            }
            weightedSum += levelSum;
        }
        
        return weightedSum;
    }
    
public:
    int depthSumInverse(vector<NestedInteger>& nestedList) {
        return getSum(nestedList);
    }
};