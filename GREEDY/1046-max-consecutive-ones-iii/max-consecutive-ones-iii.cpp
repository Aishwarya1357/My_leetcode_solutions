class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int maxlen = 0; 
        int l = 0, r = 0; // Initialize l and r
        int zero_count = 0;

        while (r < nums.size()) {
            if (nums[r] == 0)
                zero_count++;

            while (zero_count > k) {
                if (nums[l] == 0)
                    zero_count--;
                l++;
            }  

            // Update maxlen for the current valid window
            maxlen = max(maxlen, r - l + 1);
            
            // Move right pointer
            r++;
        }
        return maxlen;
    }
};
