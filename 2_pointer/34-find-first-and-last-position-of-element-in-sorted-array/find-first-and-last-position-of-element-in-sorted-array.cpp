class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {


        vector<int>result(2,-1);

        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                result[0]=i;
                break;
            }
        }

        for(int j=nums.size()-1;j>=0;j--){
            if(nums[j]==target){
                result[1]=j;
                break;
            }
        }

        return result;}



};