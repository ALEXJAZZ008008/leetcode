#include <vector>

using namespace std;

class Solution
{
    public:
        double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) 
        {
            double median = 0;

            int nums1_size = nums1.size();
            int nums2_size = nums2.size();

            int total_size = nums1_size + nums2_size;

            int next_nums1_index = 0;
            int next_nums2_index = 0;

            int left_value = 0;
            int right_value = 0;

            for(int i = 0; i <= total_size / 2; ++i)
            {
                left_value = right_value;

                if(next_nums2_index >= nums2_size || (next_nums1_index < nums1_size && 
                nums1[next_nums1_index] <= nums2[next_nums2_index]))
                {
                    right_value = nums1[next_nums1_index];
                    ++next_nums1_index;
                }
                else
                {
                    right_value = nums2[next_nums2_index];
                    ++next_nums2_index;
                }
            }

            if(total_size % 2 == 0)
            {
                median = (right_value + left_value) / 2.0;
            }
            else
            {
                median = right_value;
            }

            return median;
        }
};
