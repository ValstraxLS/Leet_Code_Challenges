"""
You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order,
and each of their nodes contains a single digit. Add the two numbers and return the sum as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.



Example 1:
Input: l1 = [2,4,3], l2 = [5,6,4]
Output: [7,0,8]
Explanation: 342 + 465 = 807.

Example 2:
Input: l1 = [0], l2 = [0]
Output: [0]

Example 3:
Input: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]
Output: [8,9,9,9,0,0,0,1]


Constraints:

The number of nodes in each linked list is in the range [1, 100].
0 <= Node.val <= 9
It is guaranteed that the list represents a number that does not have leading zeros.
"""


def convToLink(lst: [int]):
    head = current = ListNode()
    lst = lst[::-1]
    for i in lst:
        current.next = ListNode(i)
        current = current.next
    return head.next

def convToList(link):
    lst = []
    while link is not None:
        lst += [link.val]
        link = link.next
    return lst

# Definition for singly-linked list.
class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def addTwoNumbers(self, l1: [ListNode], l2: [ListNode]) -> [ListNode]:
        head = current = ListNode()
        carry = 0
        while l1 is not None and l2 is not None:
            current.next = ListNode(l1.val + l2.val + carry)
            carry = int(current.next.val / 10)
            current.next.val -= carry * 10
            l1, l2, current = l1.next, l2.next, current.next

        while l1 is not None:
            current.next = ListNode(l1.val + carry)
            carry = int(current.next.val / 10)
            current.next.val -= carry * 10
            l1, current = l1.next, current.next

        while l2 is not None:
            current.next = ListNode(l2.val + carry)
            carry = int(current.next.val / 10)
            current.next.val -= carry * 10
            l2, current = l2.next, current.next

        if carry > 0:
            current.next = ListNode(carry)
        return head.next


if __name__ == "__main__":
    s = Solution()
    print("Example 1:\nInput: l1 = [2,4,3], l2 = [5,6,4]\nOutput: [7,0,8]\nExplanation: 342 + 465 = 807.")
    print(f"Output: {convToList(Solution.addTwoNumbers(s, convToLink([2, 4, 3]), convToLink([5, 6, 4])))}\n")

    print("Example 2:\nInput: l1 = [0], l2 = [0]\nOutput: [0]")
    print(f"Output: {convToList(Solution.addTwoNumbers(s, convToLink([0]), convToLink([0])))}\n")

    print("Example 3:\nInput: l1 = [9,9,9,9,9,9,9], l2 = [9,9,9,9]\nOutput: [8,9,9,9,0,0,0,1])")
    print(f"Output: {convToList(Solution.addTwoNumbers(s, convToLink([9, 9, 9, 9, 9, 9, 9]), convToLink([9, 9, 9, 9])))}\n")
