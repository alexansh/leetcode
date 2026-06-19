#include <vector>

class Solution {
private:
    void generateSubsets(int index, std::vector<int>& nums, std::vector<int>& current, std::vector<std::vector<int>>& result) {

        if (index == nums.size()) {
            result.push_back(current);
            return;
        }

        current.push_back(nums[index]);
        generateSubsets(index + 1, nums, current, result);

        current.pop_back();

        generateSubsets(index + 1, nums, current, result);
    }

public:
    std::vector<std::vector<int>> subsets(std::vector<int>& nums) {
        std::vector<std::vector<int>> result;
        std::vector<int> current;
        
        generateSubsets(0, nums, current, result);
        return result;
    }
};
