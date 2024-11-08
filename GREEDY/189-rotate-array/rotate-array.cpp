#include <vector>

class Solution {
public:
    void rotate(std::vector<int>& nums, int k) {
        int n = nums.size();
        k = k % n;  // Handle cases where k is greater than n
        
        // Step 1: Store the last k elements in a temporary array
        std::vector<int> temp(nums.end() - k, nums.end());
        
        // Step 2: Shift the first n-k elements to the right
        for (int i = n - 1; i >= k; i--) {
            nums[i] = nums[i - k];
        }
        
        // Step 3: Copy the elements from temp to the beginning of nums
        for (int i = 0; i < k; i++) {
            nums[i] = temp[i];
        }
    }
};
