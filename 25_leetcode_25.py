def reverseKGroup(self, head: Optional[ListNode], k: int) -> Optional[ListNode]:
    dummy = ListNode(0,head)
    groupPrev=dummy

    while True:
        kth=self.getKth(groupPrev, k)
        if not kth:
            break


        def getKth(self, curr, k):
            while curr and k>0:
                curr=curr.next
                k-=1
            return curr
        
