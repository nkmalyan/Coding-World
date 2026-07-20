class Solution {
public:
    std::vector<int> twoSum(std::vector<int>& nums, int target) {
        std::unordered_map<int, int> prevMap;

        for (int i = 0; i < nums.size(); ++i) {
            int complement = target - nums[i];

            if (prevMap.find(complement) != prevMap.end()) {

                return {prevMap[complement], i};
            }
            prevMap[nums[i]] = i;
        }
        return {};
    }    
};
