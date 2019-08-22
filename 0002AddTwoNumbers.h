#ifndef __0002__
#define __0002__

#include "precomp.h"

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	if (!l1 || !l2) return l1 ? l1 : l2;
	ListNode* head = new ListNode(-1), *curr = head;
	int32_t carry = 0;
	while (l1 || l2 || carry)
	{
		int32_t value = (l1 ? l1->val : 0) + (l2 ? l2->val : 0) + carry;
		if (value >= 10)
		{
			carry = value / 10;
			value %= 10;
		}
		else
		{
			carry = 0;
		}
		ListNode* node = new ListNode(value);
		curr->next = node;
		curr = node;
		if (l1) l1 = l1->next;
		if (l2) l2 = l2->next;
	}
	return head->next;
}

void testcase_0002()
{
	ListNode a1(2), a2(4), a3(3), b1(5), b2(6), b3(4);
	a1.next = &a2; a2.next = &a3; b1.next = &b2; b2.next = &b3;
	ListNode* res = addTwoNumbers(&a1, &b1);
	printf("0002: ");
	while (res)
	{
		printf("%d ", res->val);
		res = res->next;
	}
	printf("\n");
}

#endif
