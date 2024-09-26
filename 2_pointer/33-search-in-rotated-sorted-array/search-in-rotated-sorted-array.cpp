class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=0;
        int r=n-1;
        while(l<=r){
            int mid=(l+r)/2;

            if(target==nums[mid]){
                return mid;
            }

            if(nums[mid]>=nums[0]){
                if(nums[0]>target|| nums[mid]<target){
                    l=mid+1;
                }
                else{
                    r=mid-1;
                }
            }

            else{

                if(target<nums[mid]||target>nums[n-1]){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }




            
        }

        return -1;
        
    }
};