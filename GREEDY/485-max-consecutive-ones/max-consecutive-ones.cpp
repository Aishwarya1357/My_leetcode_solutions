class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int count=0;//to track the number of 1's

        int maxlen=0;// to track the max count

        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
               
            }
              
              
         else{maxlen=max(count, maxlen);
         count=0;}
        }

        maxlen=max(maxlen,count);
        return maxlen;




        
    }
};