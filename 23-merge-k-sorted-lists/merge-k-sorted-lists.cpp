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
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int,int>,std::vector<std::pair<int, int>>,greater<pair<int,int>>> queue;
        for(int i = 0; i<lists.size();++i){
            if(lists[i] == nullptr) continue;
            queue.push({lists[i]->val, i});
        }
        ListNode* insert = new ListNode();
        ListNode* ans = insert;
        int val, ind;
        while(!queue.empty()){
            tie(val,ind) = queue.top();
            queue.pop();
            insert->next = lists[ind];
            insert = lists[ind];
            lists[ind] = lists[ind]->next;
            if(lists[ind] != nullptr){
                queue.push({lists[ind]->val,ind});
            } 
        }

        return ans->next;
    }
};