# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def addTwoNumbers(self, l1: Optional[ListNode], l2: Optional[ListNode]) -> Optional[ListNode]:
        carry = 0

        linkedList = ListNode(0,None)
        res2 = linkedList
        while l1 != None or l2 != None:
            val1 = 0
            val2 = 0
            if l1 != None:
                val1 = l1.val
            if l2 != None:
                val2 = l2.val
            summe = val1 + val2 + carry
            carry = int(summe>9)
            summe = summe % 10
            if l1 != None:
                l1 = l1.next
            if l2 != None:
                l2 = l2.next
            res = ListNode(summe, None)
            res2.next = res
            res2 = res
        if carry == 1:
            res = ListNode(1, None)
            res2.next = res
            res2 = res
        return linkedList.next
