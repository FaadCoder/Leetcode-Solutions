class Solution {
    enum color{
        noColor,
        white,
        black
    };
    
    bool isPossibleToColorGraphUsingTwoColors(vector<vector<int>>& graph,int startVertex,vector<color> &colors,color currentAvailableColor)
    {
        colors[startVertex] = currentAvailableColor;
        for(auto child:graph[startVertex])
        {
            if(colors[child] == noColor)
            {
                color nextAvailableColor = (currentAvailableColor == white) ? black : white;
                if(!isPossibleToColorGraphUsingTwoColors(graph,child,colors,nextAvailableColor))
                    return false;
            }
            else if(colors[child] == colors[startVertex])
                return false;
        }
        return true;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int numberOfVertices = graph.size();
        vector<color> colors(numberOfVertices,noColor);
        for(int vertex = 0; vertex < numberOfVertices; vertex++)
        {
            if(colors[vertex] == noColor and !isPossibleToColorGraphUsingTwoColors(graph,vertex,colors,white))
            {
                    return false;
            }
        }
        return true;
    }
};