#include <climits>
#include <vector>
#include <algorithm>

using namespace std;

class Solution
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
        {
            double median = 0;

            int nums1_size = nums1.size();
            int nums2_size = nums2.size();

            int merged_array_size = nums1_size + nums2_size;
            int median_index = merged_array_size / 2;

            int lowest_nums1_pivot = max(0, median_index - nums2_size);
            int highest_nums1_pivot = min(nums1_size, median_index);

            int nums1_left_value = 0;
            int nums2_right_value = 0;

            int nums2_left_value = 0;
            int nums1_right_value = 0;

            while(lowest_nums1_pivot <= highest_nums1_pivot)
            {
                int nums1_pivot_index = lowest_nums1_pivot + ((highest_nums1_pivot - lowest_nums1_pivot) / 2);
                int nums2_pivot_index = median_index - nums1_pivot_index;

                if(nums1_pivot_index == 0)
                {
                    nums1_left_value = INT_MIN;
                }
                else
                {
                    nums1_left_value = nums1.at(nums1_pivot_index - 1);
                }

                if(nums2_pivot_index == nums2_size)
                {
                    nums2_right_value = INT_MAX;
                }
                else
                {
                    nums2_right_value = nums2.at(nums2_pivot_index);
                }

                if(nums2_pivot_index == 0)
                {
                    nums2_left_value = INT_MIN;
                }
                else
                {
                    nums2_left_value = nums2.at(nums2_pivot_index - 1);
                }

                if(nums1_pivot_index == nums1_size)
                {
                    nums1_right_value = INT_MAX;
                }
                else
                {
                    nums1_right_value = nums1.at(nums1_pivot_index);
                }

                if(nums1_left_value <= nums2_right_value)
                {
                    if(nums2_left_value <= nums1_right_value)
                    {
                        break;
                    }
                    else
                    {
                        lowest_nums1_pivot = nums1_pivot_index + 1;
                    }
                }
                else
                {
                    highest_nums1_pivot = nums1_pivot_index - 1;
                }
            }

            if(merged_array_size % 2 == 0)
            {
                median = (static_cast<double>(max(nums1_left_value, nums2_left_value)) + static_cast<double>(min(nums1_right_value, nums2_right_value))) / 2.0;
            }
            else
            {
                median = min(nums1_right_value, nums2_right_value);
            }

            return median;
        }
};
