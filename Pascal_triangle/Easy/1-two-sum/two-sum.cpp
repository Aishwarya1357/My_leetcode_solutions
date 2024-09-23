#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> num_map; // to store the number and its index
        
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];
            
            // If complement exists in the map, we found the solution
            if (num_map.find(complement) != num_map.end()) {
                return {num_map[complement], i};
            }
            
            // Otherwise, add the number and its index to the map
            num_map[nums[i]] = i;
        }
        
        // If no solution is found, return an empty vector (though per the problem statement, this won't happen)
        return {};
    }
};
