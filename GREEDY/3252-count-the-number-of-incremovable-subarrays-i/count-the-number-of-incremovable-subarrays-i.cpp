#include <iostream>
#include <vector>
using namespace std;

// Function to check if the array is strictly increasing
bool increasing(const vector<int>& al) {
    for (int i = 1; i < al.size(); i++) {
        if (al[i] <= al[i - 1]) {
            return false; // Return false if the array is not strictly increasing
        }
    }
    return true; // Return true if the array is strictly increasing
}

class Solution {
public:
    int incremovableSubarrayCount(vector<int>& nums) {
        int count = 0; // Initialize a counter for incremovable subarrays

        // Iterate through all possible subarrays using nested loops
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i; j < nums.size(); j++) {
                // Create a vector to hold the remaining elements after removing the subarray
                vector<int> al;
                for (int k = 0; k < nums.size(); k++) {
                    if (k < i || k > j) { // Add elements outside the subarray's range
                        al.push_back(nums[k]);
                    }
                }

                // Check if the remaining elements are strictly increasing
                if (increasing(al)) {
                    count++; // If so, increment the count of incremovable subarrays
                }
            }
        }

        return count; // Return the total count of incremovable subarrays
    }
};


