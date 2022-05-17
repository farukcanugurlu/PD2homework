#include<stdio.h>
#include<stdlib.h>

struct Node {
	int age;
	Node* next;
};

typedef struct Node Node;

Node* deleteSecondRepeatedAge(Node* head, int age) {

	Node* tempHead = head;
	Node* oneNodeBefore = NULL;



	if (head == NULL || head->next == NULL)
		return head;

	int isSecond = 0;
	
	while (tempHead != NULL) {

		if (tempHead->age == age) {
			if (isSecond) {
				oneNodeBefore->next = tempHead->next;
				free(tempHead);
				break;
			}
			isSecond = 1;
		}
		oneNodeBefore = tempHead;
		tempHead = tempHead->next;
		
	}
	return head;
}

int main() {

	Node* head = NULL;
	for (int i = 1; i <= 5; i++) {
		Node* node = (Node*)malloc(sizeof(Node));
		node->age = 1;
		node->next = head;
		head = node;
	}
	head = deleteSecondRepeatedAge(head,1);
	while (head != NULL)
	{
		printf("%d\n", head->age);
		head = head->next;
	}
}
