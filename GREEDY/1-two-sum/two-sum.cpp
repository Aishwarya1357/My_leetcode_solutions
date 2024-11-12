

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {

        map<int, int>mpp;
        int n=nums.size();
        for(int i=0;i<nums.size();i++){
            int first=nums[i];
            int required=target-first;

            if(mpp.find(required)!=mpp.end()){
                return {mpp[required],i};
            }
            mpp[first]=i;
        }
        return{-1,-1};

    }
};
