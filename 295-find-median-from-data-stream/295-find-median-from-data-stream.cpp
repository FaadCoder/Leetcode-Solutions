class MedianFinder
{
    priority_queue<int> lowerMaxHeap;
    priority_queue<int, vector < int>, greater < int>> upperMinHeap;

    void balanceHeaps()
    {
        if (lowerMaxHeap.size() > (1 + upperMinHeap.size()))
        {
            upperMinHeap.push(lowerMaxHeap.top());
            lowerMaxHeap.pop();
        }
        else if ((lowerMaxHeap.size() + 1) < upperMinHeap.size())
        {
            lowerMaxHeap.push(upperMinHeap.top());
            upperMinHeap.pop();
        }
    }

    public:
        MedianFinder()
        {
            while (!lowerMaxHeap.empty())
                lowerMaxHeap.pop();

            while (!upperMinHeap.empty())
                upperMinHeap.pop();
        }

    void addNum(int num)
    {
        if (!upperMinHeap.empty() and num > upperMinHeap.top())
            upperMinHeap.push(num);
        else
            lowerMaxHeap.push(num);

       	// balance the heaps.
        balanceHeaps();
    }

    double findMedian()
    {
        if (lowerMaxHeap.empty())
            return 0.0;
        if (lowerMaxHeap.size() == upperMinHeap.size())
            return (1.0 *upperMinHeap.top() + 1.0 *lowerMaxHeap.top()) / 2.0;
        return lowerMaxHeap.size() > upperMinHeap.size() ? lowerMaxHeap.top() : upperMinHeap.top();
    }
};

/**
 *Your MedianFinder object will be instantiated and called as such:
 *MedianFinder* obj = new MedianFinder();
 *obj->addNum(num);
 *double param_2 = obj->findMedian();
 */