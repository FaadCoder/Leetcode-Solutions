struct PersonInfo{
    string name;
    int height;
    PersonInfo (string _name, int _height): name(_name), height(_height){}
};

class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        vector<PersonInfo> people;
        
        for(int idx = 0; idx < size(names); idx++)
            people.push_back(PersonInfo(names[idx], heights[idx]));
        
        sort(begin(people), end(people), [&](PersonInfo &person1, PersonInfo &person2){
            return person1.height > person2.height;
        });
        
        vector<string> sortedNames;
        
        for(PersonInfo &person : people)
            sortedNames.push_back(person.name);
        
        return sortedNames;
    }
};