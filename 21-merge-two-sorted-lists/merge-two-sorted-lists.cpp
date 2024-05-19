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
        if(list1 == nullptr) return list2;
        if(list2 == nullptr) return list1;

        ListNode* insertPoint = new ListNode();
        ListNode* sortedList = insertPoint;

        while(list1 || list2){
            if(!list1) {
                insertPoint->next = list2;
                return sortedList->next;
            }
            else if(!list2) {
                insertPoint->next = list1;
                return sortedList->next;
            }
            else if(list1->val<=list2->val){
                insertPoint->next = list1;
                insertPoint = list1;
                list1 = list1->next;            
            }
            else{
                insertPoint->next = list2;
                insertPoint = list2;
                list2 = list2->next;
            }
        }
        return sortedList->next;
    }
};