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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* nFromEnd = head;
        ListNode* end = head;
        // Let end be n ahead of nFromEnd
        for(int i = 0; i<n;++i){
            end = end->next;
        }
        if(end == nullptr) return head->next;
        while(end->next != nullptr){
            end = end->next;
            nFromEnd = nFromEnd->next;
        }
        nFromEnd->next = nFromEnd->next ? nFromEnd->next->next : nullptr;
        return head;
    }
};