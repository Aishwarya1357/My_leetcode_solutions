class Solution {
public:
    int missingNumber(vector<int>& nums) {

int N=nums.size();
int sum=(N*(N+1))/2;
int arsum=0;
for(int i=0;i<N;i++){
    arsum=arsum+nums[i];

}

return (sum-arsum);


        
    }
};