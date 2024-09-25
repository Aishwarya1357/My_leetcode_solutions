class Solution {
public:

    int firstoccurence(vector<int>& nums, int target) {
        int fo = -1;
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;  // Correct calculation of mid

            if (nums[mid] > target) {
                r = mid - 1;
            } 
            else if (nums[mid] < target) {
                l = mid + 1;
            } 
            else {
                fo = mid;  // Update first occurrence
                r = mid - 1;  // Continue searching in the left half
            }
        }
        return fo;
    }

    int lastoccurence(vector<int>& nums, int target) {
        int fl = -1;
        int l = 0;
        int r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;  // Correct calculation of mid

            if (nums[mid] > target) {
                r = mid - 1;
            } 
            else if (nums[mid] < target) {
                l = mid + 1;
            } 
            else {
                fl = mid;  // Update last occurrence
                l = mid + 1;  // Continue searching in the right half
            }
        }
        return fl;
    }

    vector<int> searchRange(vector<int>& nums, int target) {
        int fo = firstoccurence(nums, target);  // Correct function call
        int fl = lastoccurence(nums, target);   // Correct function call

        vector<int> result = {fo, fl};  // Correct initialization of result vector
        return result;
    }
};

