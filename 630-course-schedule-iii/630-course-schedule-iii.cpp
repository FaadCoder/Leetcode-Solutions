class Solution {
public:
    int scheduleCourse(vector<vector<int>>& courses) {
        sort(courses.begin(),courses.end(),[&](vector<int> &course1, vector<int> &course2){
            return (course1[1]==course2[1])?course1[0]<course2[0]:course1[1]<course2[1];
        });
        
        priority_queue<int> maxHeap;
        int totalTime = 0;
        
        for(vector<int> &course:courses)
        {
            totalTime += course[0];
            maxHeap.push(course[0]);
            if(totalTime > course[1])
            {
                totalTime -= maxHeap.top();
                maxHeap.pop();
            }
        }
        
        return maxHeap.size();
    }
};