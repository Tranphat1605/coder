#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX 100

// Stack ký tự (dùng cho chuyển đổi)
typedef struct {
    char items[MAX];
    int top;
} StackChar;

// Stack số nguyên (dùng cho tính toán)
typedef struct {
    int items[MAX];
    int top;
} StackInt;

// Hàm cho stack ký tự
void initChar(StackChar* s) { s->top = -1; }
int is_emptyChar(StackChar* s) { return s->top == -1; }
void pushChar(StackChar* s, char val) { s->items[++(s->top)] = val; }
char popChar(StackChar* s) { return s->items[(s->top)--]; }
char peekChar(StackChar* s) { return s->items[s->top]; }

// Hàm cho stack số
void initInt(StackInt* s) { s->top = -1; }
int is_emptyInt(StackInt* s) { return s->top == -1; }
void pushInt(StackInt* s, int val) { s->items[++(s->top)] = val; }
int popInt(StackInt* s) { return s->items[(s->top)--]; }

// Hàm tính độ ưu tiên toán tử
int precedence(char op) {
    if (op == '+' || op == '-') return 1;
    if (op == '*' || op == '/') return 2;
    return 0;
}

// Chuyển infix → postfix (kết quả trả về trong `output`)
void infix_to_postfix(const char* input, char* output) {
    StackChar s;
    initChar(&s);
    int out_index = 0;
    int len = strlen(input);

    for (int i = 0; i < len; i++) {
        char ch = input[i];

        if (isspace(ch)) continue;

        if (isdigit(ch)) {
            output[out_index++] = ch;
        }
        else if (ch == '(') {
            pushChar(&s, ch);
        }
        else if (ch == ')') {
            while (!is_emptyChar(&s) && peekChar(&s) != '(') {
                output[out_index++] = popChar(&s);
            }
            popChar(&s); // bỏ '('
        }
        else if (ch == '+' || ch == '-' || ch == '*' || ch == '/') {
            while (!is_emptyChar(&s) && precedence(peekChar(&s)) >= precedence(ch) && peekChar(&s) != '(') {
                output[out_index++] = popChar(&s);
            }
            pushChar(&s, ch);
        }
    }

    while (!is_emptyChar(&s)) {
        output[out_index++] = popChar(&s);
    }

    output[out_index] = '\0'; // kết thúc chuỗi
}

// Tính toán kết quả postfix
int evaluate_postfix(const char* postfix) {
    StackInt s;
    initInt(&s);

    for (int i = 0; postfix[i] != '\0'; i++) {
        char ch = postfix[i];

        if (isdigit(ch)) {
            pushInt(&s, ch - '0'); // chuyển từ ký tự sang số
        } else {
            int b = popInt(&s);
            int a = popInt(&s);
            int result = 0;

            switch (ch) {
                case '+': result = a + b; break;
                case '-': result = a - b; break;
                case '*': result = a * b; break;
                case '/': result = a / b; break; // chú ý chia 0
            }

            pushInt(&s, result);
        }
    }

    return popInt(&s);
}

int main() {
    char input[MAX];
    char postfix[MAX];

    printf("Enter your expression:\n>> ");
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // xóa newline

    infix_to_postfix(input, postfix);

    printf("Postfix expression: %s\n", postfix);

    int result = evaluate_postfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
