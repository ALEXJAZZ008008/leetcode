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

using namespace std;

class Solution
{
    private:
        void add_list_node(ListNode* l1, ListNode* l2, ListNode* new_l, int carry)
        {
            ListNode temp_l = ListNode();

            if(l1 == nullptr)
            {
                l1 = &temp_l;
            }

            if(l2 == nullptr)
            {
                l2 = &temp_l;
            }

            new_l->val = l1->val + l2->val + carry;
            
            int new_carry = 0;

            if(new_l->val > 9)
            {
                new_carry = new_l->val / 10;
                new_l->val = new_l->val % 10;
            }

            if(l1->next != nullptr || l2->next != nullptr || new_carry != 0)
            {
                new_l->next = new ListNode();

                add_list_node(l1->next, l2->next, new_l->next, new_carry);
            }
        }

    public:
        ListNode* addTwoNumbers(ListNode* l1, ListNode* l2)
        {
            ListNode* new_l = nullptr;

            if(l1 != nullptr || l2 != nullptr)
            {
                new_l = new ListNode();

                add_list_node(l1, l2, new_l, 0);
            }

            return new_l;
        }
};
