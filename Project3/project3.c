//프로젝트명 : Project #3 : Expression Stack using Array
//작성일 : 2021년 5월 6일(목)

#include <stdio.h>
#define SIZE 100

typedef struct {
    char stack[SIZE];
    int top;
}StackType;

void init(StackType* s) {
    s->top = -1;
}

int isFull(StackType* s) {
    if (s->top == SIZE - 1) {
        return 1;
    }
    return 0;
}

int isEmpty(StackType* s) {
    if (s->top == -1) {
        return 1;
    }
    return 0;
}

int pop(StackType* s) {
    if (!isEmpty(s)) {
        int temp = s->stack[(s->top)];
        s->top--;
        return temp;
    }
    else exit(1);
}

void push(StackType* s, int data) {

    if (!isFull(s)) {
        s->top++;
        s->stack[s->top] = data;
    }
    else exit(1);
}

char peek(StackType* s) {
    if (!isEmpty(s))
        return s->stack[s->top];
    else
        exit(1);
}

int prec(char op) {

    switch (op) {
    case'(':
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

    StackType s;
    init(&s);

    for (int i = 0; i < len; i++) {
        ch = exp[i];

        if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!isEmpty(&s) && (prec(ch) <= prec(peek(&s)))) {
                convert[j++] = pop(&s);
            }
            push(&s, ch);
        }
        else if (ch == '(') {
            push(&s, ch);
        }
        else if (ch == ')') {
            top_op = pop(&s);
            while (top_op != '(') {
                convert[j++] = top_op;
                top_op = pop(&s);
            }
        }
        else {
            convert[j++] = ch;
        }
    }

    while (!isEmpty(&s)) {
        convert[j++] = pop(&s);
    }

}

int F_postfix_eval(char exp[]) {

    char ch;
    int op1, op2, data;

    StackType* s;

    init(&s);

    for (int i = 0; exp[i] != '\0'; i++)
    {
        ch = exp[i];
        if (ch != '+' && ch != '-' && ch != '*' && ch != '/') {
            data = ch - '0';
            push(&s, data);
        }
        else {

            op2 = pop(&s);
            op1 = pop(&s);

            switch (ch) {
            case '+':
                push(&s, op1 + op2);
                break;
            case '-':
                push(&s, op1 - op2);
                break;
            case '*':
                push(&s, op1 * op2);
                break;
            case '/':
                push(&s, op1 / op2);
                break;
            }
        }
    }
    return pop(&s);
}

void main()
{
    printf("I am Yu-Jeong Oh \n");
    printf("This Project is No_3 Expression Stack using Array \n\n");
    printf("2021년 5월 6일(목) 코드 작성\n\n");

    char F_original[100] = "(3+5)*((2+6)/(9-7))-1";
    char convert[100] = { '\0' };
    int result;

    F_postfix(F_original, convert);
    printf("후위 표기식 : %s\n", convert);

    result = F_postfix_eval(convert);
    printf("계산 결과 : %d\n", result);

    return 0;
}