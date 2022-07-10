class SmallestInfiniteSet
{
    set<int> orderedSet;
    public:
        SmallestInfiniteSet()
        {
            orderedSet.insert(1);
        }

    int popSmallest()
    {
        int pop = *orderedSet.begin();
        orderedSet.erase(orderedSet.find(pop));
        if (orderedSet.size() == 0)
        {
            orderedSet.insert(pop + 1);
        }
        return pop;
    }

    void addBack(int num)
    {
        if (num<*orderedSet.rbegin())
            orderedSet.insert(num);
    }
};

/**
 *Your SmallestInfiniteSet object will be instantiated and called as such:
 *SmallestInfiniteSet* obj = new SmallestInfiniteSet();
 *int param_1 = obj->popSmallest();
 *obj->addBack(num);
 */