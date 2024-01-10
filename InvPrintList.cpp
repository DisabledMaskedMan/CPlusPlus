#include <iostream>
#include <stack>
#include <assert.h>

struct ListNode {
	int val;
	struct ListNode* Node;
};

using namespace std;

void invPrintList(struct ListNode* phead)
{
	std::stack<ListNode*>nodes;

	ListNode* pNode = phead;
	while (pNode != nullptr)
	{
		nodes.push(pNode);
		pNode = pNode->Node;
	}

	while (!nodes.empty())
	{
		pNode = nodes.top();
		printf("%d ", pNode->val);
		nodes.pop();
	}
}

struct ListNode* creatList(int n)
{
	assert(n > 0);
	struct ListNode* pHead = NULL;
	struct ListNode* pTail1 = NULL;
	struct ListNode* pTail2 = NULL;
	pHead = new struct ListNode;
	if (pHead == NULL)
	{
		std::cout << "malloc Fail" << std::endl;
		return NULL;
	}
	pTail1 = pHead;
	pTail1->val = 1;
	for (int i = 2; i <= n; i++)
	{
		pTail2 = new struct ListNode;
		if (pTail2 == NULL)
		{
			std::cout << "continue malloc Fail" << std::endl;
			return pHead;
		}
		pTail2->val = i;
		pTail1->Node = pTail2;
		pTail1 = pTail2;
	}

	pTail1->Node = NULL;
	return pHead;
}

void printList(struct ListNode* phead)
{
	while (phead != NULL)
	{
		std::cout << phead->val << ' ';
		phead = phead->Node;
	}
	std::cout << std::endl;
}

void destroyList(struct ListNode* phead)
{
	assert(phead != NULL);

	while (phead != NULL)
	{
		struct ListNode* tmp = phead;
		phead = phead->Node;
		delete tmp;
	}
}

int main()
{
	struct ListNode* head = creatList(20);
	printList(head);
	invPrintList(head);
	destroyList(head);

	return 0;
}
