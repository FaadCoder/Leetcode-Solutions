class DSU
{
private:
        vector<int> par, size;
public:
        DSU(int n)
        {
            par.resize(n+1);
            size.resize(n+1);
            for (int i = 0; i <= n; i++)
                par[i] = i, size[i] = 1;
        }

    int getParent(int node)
    {
        if (node == par[node])
            return node;
        return par[node] = getParent(par[node]);
    }

    bool unionSets(int node1, int node2)
    {
        node1 = getParent(node1);
        node2 = getParent(node2);
        if (node1 == node2)
            return false;

        if (size[node1] < size[node2])
            swap(node1, node2);
        par[node2] = node1;
        size[node1] += size[node2];
        return true;
    }
};

class Pair{
 public:
    
    int distance;
    int from;
    int to;
    
    Pair(int _dist,int _from,int _to)
    {
        distance = _dist;
        from = _from;
        to = _to;
    }
    
};

struct compare{
  bool operator()(Pair &pair1, Pair &pair2){
      return pair1.distance > pair2.distance;
  };
};

class Solution
{
    int numberOfPoints;
    priority_queue<Pair,vector<Pair>,compare> pq;
    
    int manhattanDistance(vector<int> &point1,vector<int> &point2)
    {
        return abs(point1[0]-point2[0]) + abs(point1[1]-point2[1]);
    }
    
    void formGraph(vector<vector <int>> &points)
    {
        for (int idx1 = 0; idx1 < points.size(); idx1++)
        {
            for (int idx2 = idx1+1; idx2 < points.size(); idx2++) {
                pq.push(Pair(manhattanDistance(points[idx1],points[idx2]),idx1,idx2));
            }
        }
    }

    int getMinCost()
    {
        DSU dsu(numberOfPoints);
        
        int minCost = 0;
        
        while(!pq.empty())
        {
            Pair top = pq.top();
            pq.pop();
            int cost = top.distance;
            int from = top.from;
            int to = top.to;
            if(dsu.unionSets(from,to))
                minCost+=cost;
            
        }
            
        return minCost;
    }
    
    public:
        int minCostConnectPoints(vector<vector < int>> &points)
        {
            numberOfPoints = points.size();
            formGraph(points);
            return getMinCost();
        }
};