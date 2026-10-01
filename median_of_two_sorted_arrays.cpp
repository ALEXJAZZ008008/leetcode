#include <cmath>
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
            
            double median_position = (nums1_size + nums2_size) / 2.0;

            int next_nums1_index = 0;
            int next_nums2_index = 0;

            bool values_still_in_nums1 = false;
            bool values_still_in_nums2 = false;

            int next_nums1_value = 0;
            int next_nums2_value = 0;

            int left_value = 0;
            int right_value = 0;

            for(int i = 0; i <= median_position; ++i)
            {
                if(next_nums1_index < nums1_size)
                {
                    next_nums1_value = nums1.at(next_nums1_index);

                    values_still_in_nums1 = true;
                }
                else
                {
                    values_still_in_nums1 = false;
                }

                if(next_nums2_index < nums2_size)
                {
                    next_nums2_value = nums2.at(next_nums2_index);

                    values_still_in_nums2 = true;
                }
                else
                {
                    values_still_in_nums2 = false;
                }

                if(values_still_in_nums1)
                {
                    if(values_still_in_nums2)
                    {
                        if(next_nums1_value <= next_nums2_value)
                        {
                            left_value = right_value;
                            right_value = next_nums1_value;

                            ++next_nums1_index;
                        }
                        else
                        {
                            left_value = right_value;
                            right_value = next_nums2_value;

                            ++next_nums2_index;
                        }
                    }
                    else
                    {
                        left_value = right_value;
                        right_value = next_nums1_value;

                        ++next_nums1_index;
                    }
                }
                else
                {
                    if(values_still_in_nums2)
                    {
                        left_value = right_value;
                        right_value = next_nums2_value;

                        ++next_nums2_index;
                    }
                }
            }

            if(median_position > floor(median_position))
            {
                median = right_value;
            }
            else
            {
                median = (right_value + left_value) / 2.0;
            }

            return median;
        }
};
