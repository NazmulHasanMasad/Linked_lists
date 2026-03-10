def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
    curr=head
    group=0
    while curr and group<k:
        curr=curr.next
        group+=1

    if group==k:
        curr=reverseKGroup(curr,k)
        while group>0:
            mp = head.next
            head.next = cur
            cur = head
            head = tmp
            group -= 1
        head=curr
        return head



    