class Solution {
public:
    int missingNumber(vector<int>& nums) {

        int XOR1=0;
        int XOR2=0;
        int N=nums.size();
        for(int i=0;i<N;i++){
            XOR1=XOR1^nums[i];
            XOR2=XOR2^(i+1);

        }
        return XOR1^XOR2;




        
    }
};