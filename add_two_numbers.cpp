/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <string>

using namespace std;

class Solution
{
    private:
        void list_to_string(ListNode* l, string& l_to_string)
        {
            l_to_string += to_string(l->val);

            if(l->next != nullptr)
            {
                list_to_string(l->next, l_to_string);
            }
        }

        void string_to_list(ListNode* l, const string& l_as_string, int l_as_string_position, int l_as_string_size)
        {
            l->val = stoi(string(1, l_as_string.at(l_as_string_position)));

            if(++l_as_string_position < l_as_string_size)
            {
                l->next = new ListNode();

                string_to_list(l->next, l_as_string, l_as_string_position, l_as_string_size);
            }
        }

    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            ListNode* lsummed_number = nullptr;

            string l1_to_string = "";
            list_to_string(l1, l1_to_string);
            reverse(l1_to_string.begin(), l1_to_string.end());

            string l2_to_string = "";
            list_to_string(l2, l2_to_string);
            reverse(l2_to_string.begin(), l2_to_string.end());

            string summed_number = to_string(stoi(l1_to_string) + stoi(l2_to_string));
            reverse(summed_number.begin(), summed_number.end());

            lsummed_number = new ListNode();

            string_to_list(lsummed_number, summed_number, 0, summed_number.size());

            return lsummed_number;
        }
};
