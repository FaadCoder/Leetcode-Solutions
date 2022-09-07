/*
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};
*/

class Solution {
    
    // DS to store the importance of Direct subordinates to each ID.
    unordered_map<int, int> importance;
    
    // DS to store Employee Object to corresponding Id.
    unordered_map<int, Employee*> idToEmployeeMap;
    
    int populateImportance(int src)
    {
        importance[src] += idToEmployeeMap[src]->importance;
        int directSubordinatesImportance = 0;
        
        for(auto child : idToEmployeeMap[src]->subordinates)
        {
            directSubordinatesImportance += populateImportance(child);
        }
        
        importance[src] += directSubordinatesImportance;
        
        return importance[src];
    }
    
public:
    int getImportance(vector<Employee*> employees, int id) {
        
        unordered_map<int, int> indegreeMap;
        
        for(Employee *employee : employees)
        {
            if(!indegreeMap.count(employee->id))
                indegreeMap[employee->id] = 0;
            
            idToEmployeeMap[employee->id] = employee;
            
            for(auto &child : employee->subordinates)
                indegreeMap[child] += 1;
        }
        
        for(auto it : indegreeMap)
            if(it.second == 0)
                populateImportance(it.first);
        
        return importance[id];
        
    }
};