#include "addTwoNumbers.h"

using namespace std;

int main() {
	ListNode a(0), b(0), c(0), d(0), e(0), f(0);
	a.val = 2;
	a.next = &b;
	b.val = 4;
	b.next = &c;
	c.val = 3;

	d.val = 5;
	d.next = &e;
	e.val = 6;
	e.next = &f;
	f.val = 4;

	Solution s;
	ListNode *l;
	l = s.addTwoNumbers(&a, &d);
	cout << "[";
	while (l)
	{
		cout << l->val << " ";
		l = l->next;
	}
	cout << "]" << endl;
	system("pause");
	return 0;
}