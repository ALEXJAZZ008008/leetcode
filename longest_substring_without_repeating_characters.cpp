#include <string>
#include <unordered_set>

using namespace std;

class Solution
{
    public:
        int lengthOfLongestSubstring(string s)
        {
            int longest_substring_size = 0;

            unordered_set<char> seen_chars = {};

            int left = 0;

            for(int right = 0; right < s.size(); ++right)
            {
                while(seen_chars.find(s[right]) != seen_chars.end())
                {
                    seen_chars.erase(s[left]);
                    ++left;
                }

                seen_chars.insert(s[right]);

                int current_substring_size = right - left + 1;

                if(current_substring_size > longest_substring_size)
                {
                    longest_substring_size = current_substring_size;
                }
            }

            return longest_substring_size;
        }
};
