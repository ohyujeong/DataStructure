//프로젝트명 : Project #2 : Selection Sort using Linked List
//작성일 : 2021년 5월 7일(금)

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

typedef struct doubleListNode {
	int data;
	struct doubleListNode* llink;
	struct doubleListNode* rlink;
}Node;

Node* createNode() {

	Node* LList = (Node*)malloc(sizeof(Node));
	LList->data = NULL;

	LList->rlink = NULL;
	LList->llink = NULL;

	return LList;
}

void addNode(Node* L, int data) {

	Node* newNode = (Node*)malloc(sizeof(Node));
	newNode->data = data;
	newNode->llink = NULL;
	newNode->rlink = NULL;

	if (L->rlink == NULL) {
		L->rlink = newNode;
		newNode->llink = L;
	}
	else {
		Node* now = L;
		while (now->rlink != NULL)
		{
			now = now->rlink;
		}
		now->rlink = newNode;
		newNode->llink = now;
	}
}

void printList(Node* L) {
	Node* now;
	now = L;
	while (L->rlink != NULL) {
		if (L->data != NULL) {
			printf("%d, ", L->data);
		}
		L = L->rlink;
	}
	printf("%d", L->data);
}

void selectionSort(Node* L) {

	Node* now = L;
	Node* min;
	Node* next;
	int temp;

	for (; now != NULL;) {
		min = now;
		next = now->rlink;
		for (; next != NULL;) {
			if (min->data > next->data)
				min = next;
			next = next->rlink;
		}
		temp = now->data;
		now->data = min->data;
		min->data = temp;
		printf("\n");
		printList(L);
		now = now->rlink;
	}
}

void reversePrint(Node* L) {

	Node* now;
	now = L;

	while (L->rlink != NULL) {
		L = L->rlink;
	}
	printf(" %d", L->data);

	while (L->llink != NULL) {
		if (L->llink->data != NULL) {
			printf(" %d", L->llink->data);
		}
		L = L->llink;
	}

}

int main() {

	printf("I am Yu-Jeong Oh \n");
	printf("This Project is No_2 Selection Sort using Linked List \n\n");
	printf("2021년 5월 7일(금) 코드 작성\n");

	Node* LList;
	LList = createNode();

	int ArrList[10];

	for (int i = 0; i < 10; i++) {
		printf("데이터를 입력하세요: ");
		scanf("%d", &ArrList[i]);
		addNode(LList, ArrList[i]);
		printList(LList);
		printf("\n");
	}

	printf("\n정렬 단계");
	selectionSort(LList);

	printf("\n\n내림차순 정렬 : ");
	reversePrint(LList);

}
