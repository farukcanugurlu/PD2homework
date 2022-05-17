#include<stdio.h>
#include<stdlib.h>

struct Node {
	int number;
	struct Node* next;
};
typedef struct Node Node;

Node* changeFirstAndLast(Node* head) {
	Node* tempHead = head;

	if (tempHead == NULL || tempHead->next == NULL)
		return head;

	while (tempHead->next->next != NULL) {
		tempHead = tempHead->next;
	}
	Node* lastNode = tempHead->next;
	lastNode->next = head->next;
	tempHead->next = head;
	head->next = NULL;
	head = lastNode;
	return head;
}
int main() {
    int i;
	Node* head = NULL;
	for (i = 1; i <= 6; i++) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->number = i;
		node->next = head;
		head = node;
	}
	head = changeFirstAndLast(head);

	while (head != NULL)
	{
		printf("%d\n", head->number);
		head = head->next;
	}
}
