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
class Solution {
public:
    // First Time working with pointers
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* resultStart = new ListNode();
        cout << (*resultStart).val;
        ListNode* index = resultStart;
        int carry = 0;
        int sum = 0;
        while (l1 != nullptr || l2 != nullptr){
            // Calculate sum and Carry
            int val1 = (l1 != nullptr) ? (*l1).val : 0;
            int val2 = (l2 != nullptr) ? (*l2).val : 0;

            sum = val1 + val2 + carry;
            carry = (sum < 10) ? 0 : 1;
            sum = sum % 10;

            // Add Element and move pointer
            (*index).next = new ListNode(sum, NULL);
            index = (*index).next;

            // Get next element if not assigned
            l1 = (l1 == nullptr) ? l1 : (*l1).next;
            l2 = (l2 == nullptr) ? l2 : (*l2).next;
        }

        // Add carry if it is needed
        if(carry != 0){
            (*index).next = new ListNode(1, NULL);
        }
        return (*resultStart).next;
    }
};