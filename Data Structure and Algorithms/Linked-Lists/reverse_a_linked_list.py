## Creating a Linked list and then reversing a
class Node:
    def __init__(self, num):
        self.data = num
        self.next = None

    def __repr__(self):
        print("tfrdc")

class LinkedList:
    def insert(self, head: Node, nums: int):
        if head == None:
            head = Node(nums[0])
        node = head
        for num in nums:
            node.next = Node(num)
            node = node.next
        return head
    def printlist(self, head: None):
        while head:
            print(head.data, end = " ")
            head = head.next
        
class Solution:
    def reverseList(self, head: Node):
        pass
if __name__ == "__main__":
    head = None
    llist = LinkedList()
    nums = [6,3,1,7,32,4,6]
    head = llist.insert(head, nums)
    llist.printlist(head)
    