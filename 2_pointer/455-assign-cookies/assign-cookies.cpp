class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {

        sort(g.begin(),g.end());
        sort(s.begin(),s.end());



        vector<int>result;

        int i=0,j=0;
        while(i<g.size()&&j<s.size()){
            if(s[j]>=g[i]){
                result.push_back(i);
                i++;


            }
            
            j++;

        }

        return result.size();


        
    }
};