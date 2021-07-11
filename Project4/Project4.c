//프로젝트명 : Project #4 :  Expression Stack using Linked List.
//작성일 : 2021년 5월 7일(금)

#include <stdio.h>

typedef struct stackNode {
    char data;
    struct stackNode* link;
}stackNode;

stackNode* top = NULL;

void push(stackNode** top, int data) {
    stackNode* temp;
    temp = (stackNode*)malloc(sizeof(stackNode));
    temp->data = data;
    temp->link = *top;
    *top = temp;
}

int pop(stackNode** top) {
    stackNode* temp;
    int data;
    temp = *top;
    if (temp == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    else {
        data = temp->data;
        *top = temp->link;
        free(temp);
        return data;
    }
}

int peek(stackNode* top) {
    int data;
    if (top == NULL) {
        printf("Stack is empty\n");
        exit(1);
    }
    else {
        data = top->data;
        return data;
    }
}

int prec(char op) {

    switch (op) {
    case'(': case ')':
        return 0;
    case'+':case'-':
        return 1;
    case'*':case'/':
        return 2;
    }
    return -1;
}

void F_postfix(char exp[], char convert[]) {

    int j = 0;
    char ch, top_op;
    int len = strlen(exp);

    for (int i = 0; i < len; i++) {
        ch = exp[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (top != NULL && (prec(ch) <= prec(peek(top)))) {
                convert[j++] = pop(&top);
            }
            push(&top, ch);
        }
        else if (ch == '(') {
            push(&top, ch);
        }
        else if (ch == ')') {
            top_op = pop(&top);
            while (top_op != '(') {
                convert[j++] = top_op;
                top_op = pop(&top);
            }
        }
        else {
            convert[j++] = ch;
        }
    }

    while (top != NULL) {
        convert[j++] = pop(&top);
    }

}

int F_postfix_eval(char exp[]) {

    char ch;
    int op1, op2, value;


    for (int i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            value = ch - '0';
            push(&top, value);
        }
        else {

            op2 = pop(&top);
            op1 = pop(&top);

            switch (ch) {
            case '+':
                push(&top, op1 + op2);
                break;
            case '-':
                push(&top, op1 - op2);
                break;
            case '*':
                push(&top, op1 * op2);
                break;
            case '/':
                push(&top, op1 / op2);
                break;
            }
        }
    }
    return pop(&top);
}

void main() {
    printf("I am Yu-Jeong Oh \n");
    printf("This Project is No_4 Expression Stack using Linked List. \n\n");
    printf("2021년 5월 7일(금) 코드 작성 \n\n");

    stackNode* top = NULL;

    char F_original[100] = "(3+5)*((2+6)/(9-7))-1";
    char convert[100] = { '\0' };
    int result;

    F_postfix(F_original, convert);
    printf("후위 표기식 : %s\n", convert);

    result = F_postfix_eval(convert);
    printf("계산 결과 : %d\n", result);

    return 0;
}