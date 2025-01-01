#include <vector>
#include <algorithm>

class Solution {
public:
    
    std::vector<int> targetIndices(std::vector<int>& nums, int target) {
        std::sort(nums.begin(), nums.end());

        std::vector<int> result_indices;

        for (int index = 0; index < nums.size(); ++index) {
            if (nums[index] == target) {
                result_indices.push_back(index);
            }
        }

        return result_indices;
    }
};