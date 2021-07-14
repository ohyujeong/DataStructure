//프로젝트명 : Project #5 : Singly Circular Linked List for Escaping Island.

#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

typedef struct element {
	int num;
	char name[20];
}element;

element data;

typedef struct listNode {
	element data;
	struct listNode* link;
}listNode;

listNode* head;
listNode* tail;

void add(listNode* L, element data) {

	listNode* newNode;
	newNode = (struct listNode*)malloc(sizeof(listNode));

	if (tail == NULL) {
		newNode->data = data;
		newNode->link = newNode;
		head = newNode;
		tail = newNode;
	}
	else {
		newNode->data = data;
		newNode->link = tail->link;
		tail->link = newNode;
		tail = newNode;
	}
}

void printList() {

	listNode* now;
	now = tail->link;

	do {
		printf("(%d, %s)\n", now->data.num, now->data.name);
		now = now->link;
	} while (now != tail->link);
}


void Skip(int skipnumber) {

	for (int i = 0; i < 8; i++) {
		listNode* now = head;
		listNode* pre = head;
		for (int j = 0; j < skipnumber; j++) {
			pre = now;
			now = now->link;
		}
		pre->link = now->link;
		head = pre->link;
		tail = pre;
		printf("\n");
		printf("빠지는 사람 : (%d, %s)\n", now->data.num, now->data.name);
		free(now);
		printf("\n");
		printf("남아있는 사람들\n");
		printList();
	}
}

int main() {

	printf("I am Yu-Jeong Oh \n");
	printf("This Project is No_5 Singly Circular Linked List for Escaping Island. \n\n");

	int SkipNumber;

	int nums[11] = { 1,2,3,4,5,6,7,8,9,10,11 };
	char names[11][20] = { "Kim","Park","Oh","Jung","Moon","Choi",
	"Nam","James","CoCo","Gang","Alice" };


	for (int i = 0; i < 11; i++) {
		data.num = nums[i];
		strcpy(data.name, &names[i]);
		add(head, data);
	}

	srand(time(NULL));
	SkipNumber = rand() % 9 + 1;
	printf("\nSkip Number : %d\n", SkipNumber);

	Skip(SkipNumber);
	printf("\n마지막까지 남은 3명 탈출 \n");
	printList();

}