#include <string>
#include <algorithm>
#include <stdexcept>

using namespace std;

class Solution
{
    public:
        int reverse(int x)
        {
            int x_reversed = 0;

            string x_string = to_string(x);

            std::string::iterator x_string_begin = x_string.begin();

            if(x_string[0] == '-')
            {
                ++x_string_begin;
            }

            std::reverse(x_string_begin, x_string.end());

            try
            {
                x_reversed = std::stoi(x_string);
            }
            catch(const std::out_of_range&)
            {
                
            }

            return x_reversed;
        }
};
