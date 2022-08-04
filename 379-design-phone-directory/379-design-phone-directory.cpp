class PhoneDirectory {
    set<int> orderedSet;
public:
    PhoneDirectory(int maxNumbers) {
     for(int num = 0; num<maxNumbers; num++)
         orderedSet.insert(num);
    }
    
    int get() {
        if(!orderedSet.empty())
        {
            int num = *orderedSet.begin();
            orderedSet.erase(orderedSet.begin());
            return num;
        }
        return -1;
    }
    
    bool check(int number) {
        if(orderedSet.count(number))
            return true;
        return false;
    }
    
    void release(int number) {
        orderedSet.insert(number);
    }
};

/**
 * Your PhoneDirectory object will be instantiated and called as such:
 * PhoneDirectory* obj = new PhoneDirectory(maxNumbers);
 * int param_1 = obj->get();
 * bool param_2 = obj->check(number);
 * obj->release(number);
 */