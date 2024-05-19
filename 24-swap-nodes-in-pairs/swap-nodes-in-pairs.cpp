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
    ListNode* swapPairs(ListNode* head) {
        if(head == nullptr) return nullptr;
        if(head->next == nullptr) return head;
        // At least length 2
        
        ListNode* ans = head ->next;
        ListNode* node0;
        ListNode* node1 = head;
        ListNode* node2;
        
        // Swap first two
        node1->next = ans->next;
        ans->next = node1;

        node0 = node1;
        node1 = node0 ? node0->next : nullptr;
        node2 = node1 ? node1->next : nullptr;

        while(node1 && node2){
            // exchange node1 with node2
            node1->next = node2->next;// node1 points to node3 (node2->next)
            node2->next = node1;// node2 points to node1
            node0->next = node2;// node0 points to node2

            // Move nodes down the list
            node0 = node1;
            node1 = node0->next;
            node2 = node1 ? node1->next : nullptr;
        }
        return ans;
    }
};