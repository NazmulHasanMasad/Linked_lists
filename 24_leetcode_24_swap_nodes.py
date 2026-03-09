class Solution:
    def swapPairs(self, head: Optional[ListNode]) -> Optional[ListNode]:
        dummy=ListNode(0,head)
        prev,curr=dummy,head

        while curr and curr.next:
            npn=curr.next.next
            second=curr.next

            second.next=curr
            curr.next=npn
            prev.next=second

            prev=curr
            curr=npn


        return dummy.next
        