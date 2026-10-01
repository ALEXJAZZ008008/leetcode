#include <array>
#include <string>

using namespace std;

class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int longest_substring_size = 0;

            array<int, 256> last_seen;
            last_seen.fill(-1);

            int left = 0;

            for(int right = 0; right < s.size(); ++right)
            {
                char s_at_right = s[right];

                if(last_seen[s_at_right] >= left)
                {
                    left = last_seen[s_at_right] + 1;
                }

                last_seen[s_at_right] = right;


                int current_substring_size = right - left + 1;

                if(current_substring_size > longest_substring_size)
                {
                    longest_substring_size = current_substring_size;
                }
            }

            return longest_substring_size;
        }
};
