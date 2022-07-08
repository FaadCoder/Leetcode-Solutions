class Solution {
public:
      int longestLine(vector<vector<int>>& a) {
    unordered_map<int, int> horLen, verLen, diaLen, adiaLen; // "line id" -> length
    
    // What's "line id"? A constant of function(i,j) for all cells on the line: 
    // horizon: i
    // vertical: j
    // diagnal: (i-j)
    // anti-diagnal: (i+j)
    
    int maxL = 0;
    for (int i = 0; i < a.size(); i++)
      for (int j = 0; j < a[i].size(); j++) {
        if (a[i][j] == 0) // reset all lengths
          horLen[i] = verLen[j] = diaLen[i-j] = adiaLen[i+j] = 0;
        else {
          maxL = max(maxL, ++horLen[i]);
          maxL = max(maxL, ++verLen[j]);
          maxL = max(maxL, ++diaLen[i-j]);
          maxL = max(maxL, ++adiaLen[i+j]);
        }        
      }
    
    return maxL;
  }
};