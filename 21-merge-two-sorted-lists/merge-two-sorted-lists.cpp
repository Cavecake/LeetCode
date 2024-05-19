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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* head1 = list1;
        ListNode* head2 = list2;
        ListNode* sortedList;
        ListNode** insertPoint = &sortedList;
        ListNode** insert;

        while(head1 != nullptr || head2 != nullptr){
            if(head1 == nullptr) {
                *insertPoint = head2;
                return sortedList;
            }
            else if(head2 == nullptr) {
                *insertPoint = head1;
                return sortedList;
            }
            else if(head1->val > head2->val) insert = &head2;
            else insert = &head1;

            //Insert element goto next node
            (*insertPoint) = (*insert);
            insertPoint = &((*insertPoint)->next);

            // Remove top element
            *insert = (*insert)->next;
        }
        return sortedList;
    }
};