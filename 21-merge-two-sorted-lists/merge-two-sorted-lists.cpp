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
        ListNode* sortedList = nullptr;
        ListNode** insertPoint = &sortedList;
        ListNode** insert;

        while(list1 != nullptr || list2 != nullptr){
            if(list1 == nullptr) insert = &list2;
            else if(list2 == nullptr) insert = &list1;
            else if(list1->val > list2->val) insert = &list2;
            else insert = &list1;

            
            *insertPoint = *insert;
            insertPoint = &((*insertPoint)->next);
            *insert = (*insert)->next;
            

        }
        return sortedList;
    }
};