class Solution{
public:
	int lengthLongestPath(string input){
		 stringstream ss(input);
         string data;
		 // this map will store the len upto previous dir for the current explored path 
         unordered_map<int,int>len;
         int res = 0;
		 
         while(getline(ss, data, '\n'))
         {
		    // data will contain string like dir, /tsubdir1, /tsubdir2....etc
             int numTabs  = 0;   //count no of tabs
			 
             while(data[numTabs] == '\t') numTabs++;
			 
             if(numTabs == 0)
                 len[numTabs] = data.size(); //root directory
             else {
			    // length upto previous dir + len("/") + no of chars after tabs for current filename/ dirname
                 len[numTabs] = len[numTabs - 1] + 1 + data.substr(numTabs).size();   // added 1 for '/'
			 }
			 
			 // If it's a file then update the res 
             if(data.find('.') != string :: npos)
                 res = max(res, len[numTabs]);
         }
		 
        return res;
    }
};