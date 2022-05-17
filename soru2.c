#include<stdio.h>
#include<stdlib.h>

struct Node {
	int number;
	struct Node* next;
};
typedef struct Node Node;

Node* addThelastToTheBeginning(Node* head) {
	Node* tempHead = head;

	if (tempHead == NULL || tempHead->next == NULL)
		return head;

	while (tempHead->next->next != NULL)
		tempHead = tempHead->next;

	tempHead->next->next = head;
	
	head = tempHead->next;
	
	tempHead->next = NULL;
	return head;
}
int main() {
    int i;
	Node* head = NULL;
	for (i = 1; i <= 5; i++) {
	
		Node* node = (Node*)malloc(sizeof(Node));
	
		node->number = i;
	
		node->next = head;
	
		head = node;
	}
	head = addThelastToTheBeginning(head);
	while (head != NULL)
	{
		printf("%d\n", head->number);
		head = head->next;
	}
}
