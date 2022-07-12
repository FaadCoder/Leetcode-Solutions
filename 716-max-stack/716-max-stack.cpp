class MaxStack {
    list<int> doublyLinkedList;
    map<int,vector<list<int>::iterator>> orderedMap;
public:
    MaxStack() {
        doublyLinkedList.clear();
        orderedMap.clear();
    }
    
    void push(int x) {
        doublyLinkedList.push_front(x);
        orderedMap[x].push_back(doublyLinkedList.begin());
    }
    
    int pop() {
        int poppedElement = doublyLinkedList.front();
        doublyLinkedList.pop_front();
        orderedMap[poppedElement].pop_back();
        
        if(orderedMap[poppedElement].empty())
            orderedMap.erase(poppedElement);
        
        return poppedElement;
    }
    
    int top() {
        return doublyLinkedList.front();
    }
    
    int peekMax() {
        return orderedMap.rbegin()->first;
    }
    
    int popMax() {
        int it = orderedMap.rbegin()->first;
        doublyLinkedList.erase(orderedMap[it].back());
        
        orderedMap[it].pop_back();
        
        if(orderedMap[it].empty())
            orderedMap.erase(it);
        return it;
    }
};

/**
 * Your MaxStack object will be instantiated and called as such:
 * MaxStack* obj = new MaxStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->peekMax();
 * int param_5 = obj->popMax();
 */