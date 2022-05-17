#include<stdio.h>
#include<stdlib.h>

struct Node {
	int num;
	struct Node* next;
};
typedef struct Node Node;

Node* addOddToTheFirstEvenToTheEnd() {
	Node* head = NULL;
	Node* last = NULL;
	int inputNum = 0;

	printf("Sayi girebilir veya -1 yazarak cikabilirsiniz ");
	scanf("%d", &inputNum);

	while (inputNum != -1) {

		Node* tempNode = (Node*)malloc(sizeof(Node));
		tempNode->num = inputNum;
		tempNode->next = NULL;

		if (inputNum % 2 == 0) {
			if (head == NULL) {
				head = tempNode;
				last = head;
			}
			else {
				last->next = tempNode;
				last = tempNode;
			}
		}
		else {
			if (head == NULL) {
				head = tempNode;
				last = head;
			}
			else {
				tempNode->next = head;
				head = tempNode;
			}
		}

		printf("Sayi girebilir veya -1 yazarak kapatabilirsiniz ");
		scanf("%d", &inputNum);
	}
	return head;
}

int main() {

	Node* head = NULL;
	head = addOddToTheFirstEvenToTheEnd();
	while (head != NULL)
	{
		printf("%d\n", head->num);
		head = head->next;
	}
}
