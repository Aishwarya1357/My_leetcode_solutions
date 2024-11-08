class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        set<int>myset;

        for(int i=0;i<nums.size();i++){
            myset.insert(nums[i]);
        }

        int index=0;

       for(auto it : myset){
        nums[index]=it;
        index++;
       }

       return index;

        



        
    }
};
