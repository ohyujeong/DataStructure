#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

void swap(int arr[], int i, int j) {
	int temp;

	temp = arr[i];
	arr[i] = arr[j];
	arr[j] = temp;
}

int main() {
	printf("I am Yu-Jeong Oh \n");
	printf("This Project is No_1 Selection Sort using Array. \n\n");
	printf("2021년 5월 6일(목) 코드 작성 ");


	int ArrList[10];

	for (int i = 0; i < 10; i++) {
		printf("\n정수를 입력하세요 : ");
		scanf("%d", &ArrList[i]);
		switch (i) {
		case 0:
			printf(" %d", ArrList[0]);
			break;
		case 1:
			printf(" %d %d", ArrList[0], ArrList[1]);
			break;
		case 2:
			printf(" %d %d %d", ArrList[0], ArrList[1], ArrList[2]);
			break;
		case 3:
			printf(" %d %d %d %d", ArrList[0], ArrList[1], ArrList[2], ArrList[3]);
			break;
		case 4:
			printf(" %d %d %d %d %d", ArrList[0], ArrList[1], ArrList[2], ArrList[3],
				ArrList[4]);
			break;
		case 5:
			printf(" %d %d %d %d %d %d", ArrList[0], ArrList[1], ArrList[2], ArrList[3],
				ArrList[4], ArrList[5]);
			break;
		case 6:
			printf(" %d %d %d %d %d %d %d", ArrList[0], ArrList[1], ArrList[2], ArrList[3],
				ArrList[4], ArrList[5], ArrList[6]);
			break;
		case 7:
			printf(" %d %d %d %d %d %d %d %d", ArrList[0], ArrList[1], ArrList[2], ArrList[3],
				ArrList[4], ArrList[5], ArrList[6], ArrList[7]);
			break;
		case 8:
			printf(" %d %d %d %d %d %d %d %d %d", ArrList[0], ArrList[1], ArrList[2], ArrList[3],
				ArrList[4], ArrList[5], ArrList[6], ArrList[7], ArrList[8]);
			break;
		case 9:
			printf(" %d %d %d %d %d %d %d %d %d %d", ArrList[0], ArrList[1], ArrList[2], ArrList[3],
				ArrList[4], ArrList[5], ArrList[6], ArrList[7], ArrList[8], ArrList[9]);
			break;
		}
	}

	for (int i = 0; i < 9; i++) {
		int min = i;
		for (int j = i + 1; j < 10; j++) {
			if (ArrList[min] > ArrList[j]) {
				min = j;
			}
		}
		swap(ArrList, min, i);
		printf("\n(%d %d %d %d %d %d %d %d %d %d)\n\n", ArrList[0], ArrList[1], ArrList[2], ArrList[3],
			ArrList[4], ArrList[5], ArrList[6], ArrList[7], ArrList[8], ArrList[9]);
	}

	printf("역순 출력 :");
	for (int i = 0; i < 10; i++) {
		printf(" %d ", ArrList[9 - i]);
	}

}
