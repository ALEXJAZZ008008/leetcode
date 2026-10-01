#include <cstddef>

using namespace std;

class Solution
{
    public:
        vector<int> twoSum(vector<int>& nums, int target)
        {
            vector<int> twoSum_solution_indicies = {};
            bool solution_found = false;

            size_t nums_size = nums.size();

            for(size_t i = 0; i < nums_size; ++i)
            {
                int num_at_i = nums.at(i);

                for(size_t j = i + 1; j < nums_size; ++j)
                {
                    if(num_at_i + nums.at(j) == target)
                    {
                        twoSum_solution_indicies.push_back(i);
                        twoSum_solution_indicies.push_back(j);

                        solution_found = true;

                        break;
                    }
                }

                if(solution_found)
                {
                    break;
                }
            }

            return twoSum_solution_indicies;
        }
};
