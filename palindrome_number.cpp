#include <string>

using namespace std;

class Solution
{
    public:
        bool isPalindrome(int x)
        {
            bool is_palindrome = true;

            string x_to_string = to_string(x);

            int i = 0;
            int j = static_cast<int>(x_to_string.size()) - 1;

            while(i < j)
            {
                if(x_to_string.at(i) != x_to_string.at(j))
                {
                    is_palindrome = false;

                    break;
                }

                ++i;
                --j;
            }

            return is_palindrome;
        }
};
