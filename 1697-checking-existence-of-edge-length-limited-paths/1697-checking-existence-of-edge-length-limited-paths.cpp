class UnionFind
{
    unordered_map<int, int> parent, size;
    public:
        UnionFind(int n)
        {
            for (int i = 0; i <= n; i++)
                parent[i] = i, size[i] = 1;
        }

    int findParent(int child)
    {
        if (child == parent[child])
            return child;
        return parent[child] = findParent(parent[child]);
    }

    bool isConnected(int set1, int set2)
    {
        return findParent(set1) == findParent(set2);
    }

    bool unionSet(int set1, int set2)
    {
        set1 = findParent(set1);
        set2 = findParent(set2);

        if (set1 == set2)
            return false;

        if (size[set1] < size[set2])
            swap(set1, set2);
        parent[set2] = set1;
        size[set1] += size[set2];
        return true;
    }
};

class Solution {
public:
    vector<bool> distanceLimitedPathsExist(int n, vector<vector<int>>& edgeList, vector<vector<int>>& queries) {
        UnionFind unionFind(n);
        
        for(int queryIdx=0;queryIdx<queries.size(); queryIdx++)
            queries[queryIdx].push_back(queryIdx);
        
        sort(begin(queries),end(queries),[&](vector<int> &query1,vector<int> &query2){
            return query1[2]<query2[2];
        });
        
        sort(begin(edgeList),end(edgeList),[&](vector<int> &edge1,vector<int> &edge2){
            return edge1[2]<edge2[2];
        });
        
        vector<bool> queryResults(queries.size());
        int startIdx = 0;
        
        for(auto &query:queries)
        {
            while(startIdx<edgeList.size() and edgeList[startIdx][2]<query[2])
            {
                unionFind.unionSet(edgeList[startIdx][0],edgeList[startIdx][1]);
                startIdx++;
            }
            queryResults[query[3]] = unionFind.isConnected(query[0],query[1]);
        }
        return queryResults;
    }
};










