#include <stdio.h>
#include <ctype.h>

//
char input[100];
int index = 0;
char temp = 'T';
int tempCount = 0;

char newTemp() {
    return temp + tempCount++;
}

char getToken() {
    return input[index++];
}

void ungetToken() {
    index--;
}

void E();
void Eprime();
void T();
void Tprime();
void F();

void generateCode(char op, char arg1, char arg2, char result) {
    printf("%c = %c %c %c\n", result, arg1, op, arg2);
}

void E() {
    T();
    Eprime();
}

void Eprime() {
    if (input[index] == '+') {
        char op = getToken();
        char T1 = newTemp();
        T();
        char T2 = newTemp();
        generateCode(op, T1, 'E', T2);
        Eprime();
    }
}

void T() {
    F();
    Tprime();
}

void Tprime() {
    if (input[index] == '*') {
        char op = getToken();
        char F1 = newTemp();
        F();
        char F2 = newTemp();
        generateCode(op, F1, 'T', F2);
        Tprime();
    }
}

void F() {
    char temp;
    if (input[index] == '(') {
        getToken(); // Consume '('
        E();
        getToken(); // Consume ')'
    } else if (isalpha(input[index]) || isdigit(input[index])) {
        temp = getToken();
        printf("%c = %c\n", temp, temp);
    } else {
        // Handle error or exit
        printf("Syntax error\n");
        exit(1);
    }
}

int main() {
    printf("Enter an expression: ");
    scanf("%s", input);
    E();
    return 0;
}
