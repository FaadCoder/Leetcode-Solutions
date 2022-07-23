class NumberContainers {
    unordered_map<int,set<int>> numberMap;
    unordered_map<int,int> indexMap;
public:
    NumberContainers() {
       
    }
    
    void change(int index, int number) {
        set<int>::iterator it = numberMap[indexMap[index]].find(index);
        if(it!=numberMap[indexMap[index]].end())
        numberMap[indexMap[index]].erase(it);
        indexMap[index] = number;
        numberMap[number].insert(index);    
    }
    
    int find(int number) {
        if(!numberMap.count(number) or !numberMap[number].size())
            return -1;
        return *numberMap[number].begin();
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */