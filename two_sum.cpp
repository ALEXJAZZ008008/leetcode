#include <cstddef>
#include <vector>
#include <unordered_map>

using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            unordered_map<int, int> seen_numbers = {};

            for(int i = 0; i < nums.size(); ++i)
            {
                int nums_at_i = nums[i];

                unordered_map<int, int>::const_iterator match = seen_numbers.find(target - nums_at_i);

                if(match != seen_numbers.end())
                {
                    return {match->second, i};
                }

                seen_numbers.emplace(nums_at_i, i);
            }

            return {};
        }
};
