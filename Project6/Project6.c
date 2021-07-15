//프로젝트명 : Project #6 :  Doubly Circular Linked List for Escaping Island.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct element {
	int num;
	char name[20];
}element;

element data;

typedef struct doubleListNode {
	element data;
	struct doubleListNode* llink;
	struct doubleListNode* rlink;
}Node;

Node* head;

void addNode(Node** head, element data) {

	Node* newNode;
	newNode = (struct Node*)malloc(sizeof(Node));
	newNode->data = data;

	if (*head == NULL) {
		newNode->llink = newNode;
		newNode->rlink = newNode;
		*head = newNode;
	}
	else {
		Node* now = (*head);
		while (now->rlink != *head) {
			now = now->rlink;
		}
		newNode->rlink = *head;
		(*head)->llink = newNode;
		now->rlink = newNode;
		newNode->llink = now;
	}
}

void printList(Node* head) {

	Node* now;
	now = head->llink;

	do {
		now = now->rlink;
		printf("(%d, %s)\n", now->data.num, now->data.name);
	} while (now->rlink != head);

}

void reversePrintList(Node* head) {

	Node* now;
	now = head->llink;

	do {
		printf("(%d, %s)\n", now->data.num, now->data.name);
		now = now->llink;
	} while (now->rlink != head);
}

int NodeCount(Node* head) {
	int count = 0;
	Node* now = head->llink;

	do {
		count += 1;
		now = now->rlink;
	} while (now->rlink != head);

	return count;
}

void Skip(int skipnumber) {

	for (int i = 0; i < 8; i++) {
		Node* now = head;
		Node* pre = head;
		for (int j = 0; j < skipnumber; j++) {
			pre = now;
			now = now->rlink;
		}
		pre->rlink = now->rlink;
		now->rlink->llink = now->llink;
		head = pre->rlink;
		head->llink = pre;
		printf("\n");
		printf("빠지는 사람 : (%d, %s)\n", now->data.num, now->data.name);
		free(now);
		printf("\n");
		if (NodeCount(head) > 3) {
			printf("남아있는 사람들\n");
			printList(head);
		}
		else {
			printf("\n탈출하는 3명\n");
			printList(head);
		}
	}
}

void ReverseSkip(int skipnumber) {

	for (int i = 0; i < 8; i++) {
		Node* now = head;
		Node* pre = head;
		for (int j = 0; j < skipnumber; j++) {
			pre = now;
			now = now->llink;
		}
		pre->llink = now->llink;
		now->llink->rlink = pre;
		head = pre->llink;
		head->rlink = pre;
		printf("\n");
		printf("빠지는 사람 : (%d, %s)\n", now->data.num, now->data.name);
		free(now);
		if (NodeCount(head) > 3) {
			printf("남아있는 사람들\n");
			printList(head);
		}
		else {
			printf("\n탈출하는 3명\n");
			printList(head);
		}
	}
}

int main() {

	printf("I am Yu-Jeong Oh \n");
	printf("This Project is No_6 Doubly Circular Linked List for Escaping Island. \n\n");

	head = NULL;

	int nums[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
	char names[11][20] = { "Kim","Park","Oh","Jung","Moon","Choi",
	"Nam","James","CoCo","Gang","Alice" };

	for (int i = 0; i < 11; i++) {
		data.num = nums[i];
		strcpy(data.name, &names[i]);
		addNode(&head, data);
	}

	srand(time(NULL));
	int SkipNumber = rand() % 9 + 1;
	printf("\nSkip Number : %d\n", SkipNumber);

	printf("\n[순방향으로 탈출진행]\n");
	Skip(SkipNumber);

	head = NULL;

	int nums2[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
	char names2[11][20] = { "Kim","Park","Oh","Jung","Moon","Choi",
	"Nam","James","CoCo","Gang","Alice" };

	for (int i = 0; i < 11; i++) {
		data.num = nums2[i];
		strcpy(data.name, &names2[i]);
		addNode(&head, data);
	}

	printf("\n[역방향으로 탈출 진행]\n");
	ReverseSkip(SkipNumber);
}