/**
 * Definition for singly-linked list.
 * type ListNode struct {
 *     Val int
 *     Next *ListNode
 * }
 */
func addTwoNumbers(l1 *ListNode, l2 *ListNode) *ListNode {
    return func1(l1, l2, 0);

}

func func1(l1 *ListNode, l2 *ListNode, carry int) *ListNode {
	if (l1 == nil) {
		if (carry > 0) {
			return func1(&ListNode{carry, nil}, l2, 0);
		} else {
			return l2
		}
	}
	if (l2 == nil) {
		if (carry > 0) {
			return func1(l1, &ListNode{carry, nil}, 0);
		} else {
			return l1;
		}
	}

	ret := &ListNode{};
	sum := l1.Val + l2.Val + carry
	ret.Val = sum % 10;
	carry = sum / 10;

	ret.Next = func1(l1.Next, l2.Next, carry);

	return ret;
}