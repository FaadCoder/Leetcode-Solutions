class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> graph[numCourses];
        vector<int> indegree(numCourses,0);
        for(auto &course:prerequisites)
        {
            graph[course[1]].push_back(course[0]);
            indegree[course[0]]++;
        }
        
        queue<int> bfsQueue;
        for(int course = 0;course<numCourses;course++)
        {
            if(indegree[course]==0)
                bfsQueue.push(course);
        }
        int coursesCovered = 0;
        
        while(!bfsQueue.empty())
        {
            int currentCourse = bfsQueue.front();
            bfsQueue.pop();
            coursesCovered++;

            for(int nextCourse:graph[currentCourse])
            {
                indegree[nextCourse]--;
                if(indegree[nextCourse]==0)
                    bfsQueue.push(nextCourse);
            }
        }
        
        return coursesCovered==numCourses;
    }
};