#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

//
// Token types
typedef enum {
    LPAREN, RPAREN, PLUS, MULT, ID, END
} TokenType;

// Token structure
typedef struct {
    TokenType type;
    char* value;
} Token;

// Function to tokenize the input string
Token* lex(const char* input);

// Function to free the memory allocated for tokens
void freeTokens(Token* tokens);

// Function to print tokens
void printTokens(Token* tokens);

// Function prototypes for parsing
int parseE(Token* tokens, int* index);
int parseEprime(Token* tokens, int* index);
int parseT(Token* tokens, int* index);
int parseTprime(Token* tokens, int* index);
int parseF(Token* tokens, int* index);

int main() {
    const char* input = "(i + i * i)";
    Token* tokens = lex(input);

    int index = 0;
    if (parseE(tokens, &index) && tokens[index].type == END) {
        printf("Expression is valid.\n");
    } else {
        printf("Expression is invalid.\n");
    }
	printTokens(tokens);
    freeTokens(tokens);
    return 0;
}

// Parse non-terminal E
int parseE(Token* tokens, int* index) {
    int result = parseT(tokens, index);
    if (result) {
        result = parseEprime(tokens, index);
    }
    return result;
}

// Parse non-terminal Eprime
int parseEprime(Token* tokens, int* index) {
    if (tokens[*index].type == PLUS) {
        (*index)++;
        int result = parseT(tokens, index);
        if (result) {
            result = parseEprime(tokens, index);
        }
        return result;
    }
    return 1;  // Epsilon production
}

// Parse non-terminal T
int parseT(Token* tokens, int* index) {
    int result = parseF(tokens, index);
    if (result) {
        result = parseTprime(tokens, index);
    }
    return result;
}

// Parse non-terminal Tprime
int parseTprime(Token* tokens, int* index) {
    if (tokens[*index].type == MULT) {
        (*index)++;
        int result = parseF(tokens, index);
        if (result) {
            result = parseTprime(tokens, index);
        }
        return result;
    }
    return 1;  // Epsilon production
}

// Parse non-terminal F
int parseF(Token* tokens, int* index) {
    if (tokens[*index].type == ID) {
        (*index)++;
        return 1;
    } else if (tokens[*index].type == LPAREN) {
        (*index)++;
        int result = parseE(tokens, index);
        if (tokens[*index].type == RPAREN) {
            (*index)++;
            return result;
        } else {
            printf("Error: Missing closing parenthesis.\n");
            return 0;
        }
    } else {
        printf("Error: Invalid token in the expression.\n");
        return 0;
    }
}

Token* lex(const char* input) {
    // Your lexer code (provided in your original question)
	int input_len = strlen(input);
    Token* tokens = (Token*)malloc(sizeof(Token) * (input_len + 1));
    int token_count = 0;

    int i = 0;
    while (i < input_len) {
        if (input[i] == '(') {
            tokens[token_count].type = LPAREN;
            tokens[token_count].value = NULL;
            token_count++;
            i++;
        } else if (input[i] == ')') {
            tokens[token_count].type = RPAREN;
            tokens[token_count].value = NULL;
            token_count++;
            i++;
        } else if (input[i] == '+') {
            tokens[token_count].type = PLUS;
            tokens[token_count].value = NULL;
            token_count++;
            i++;
        } else if (input[i] == '*') {
            tokens[token_count].type = MULT;
            tokens[token_count].value = NULL;
            token_count++;
            i++;
        } else if (isalpha(input[i])) {
            int j = i;
            while (isalnum(input[j])) {
                j++;
            }
            int length = j - i;
            tokens[token_count].type = ID;
            tokens[token_count].value = (char*)malloc(length + 1);
            strncpy(tokens[token_count].value, input + i, length);
            tokens[token_count].value[length] = '\0';
            token_count++;
            i = j;
        } else if (isspace(input[i])) {
            i++;
        } else {
            printf("Error: Unexpected character at position %d: %c\n", i, input[i]);
            exit(1);
        }
    }

    // Add an END token to mark the end of the token stream
    tokens[token_count].type = END;
    tokens[token_count].value = NULL;

    return tokens;
}

void freeTokens(Token* tokens) {
    // Your freeTokens code (provided in your original question)
	for (int i = 0; tokens[i].type != END; i++) {
        if (tokens[i].type == ID) {
            free(tokens[i].value);
        }
    }
    free(tokens);
}

void printTokens(Token* tokens) {
    // Your printTokens code (provided in your original question)
	for (int i = 0; tokens[i].type != END; i++) {
        if (tokens[i].type == ID) {
            printf("(%d, %s) ", tokens[i].type, tokens[i].value);
        } else {
            printf("(%d) ", tokens[i].type);
        }
    }
    printf("\n");
}
