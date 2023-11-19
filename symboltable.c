#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 100

//
// Structure to represent a symbol entry
struct SymbolEntry {
    char name[50];
    // You can add more attributes as needed, e.g., type, value, scope, etc.
};

// Symbol table
struct SymbolEntry symbolTable[MAX_SYMBOLS];
int symbolCount = 0;

// Function to add a new symbol to the symbol table
void addSymbol(const char* name) {
    if (symbolCount < MAX_SYMBOLS) {
        strcpy(symbolTable[symbolCount].name, name);
        symbolCount++;
    } else {
        printf("Error: Symbol table is full\n");
    }
}

// Function to search for a symbol in the symbol table
int findSymbol(const char* name) {
    for (int i = 0; i < symbolCount; i++) {
        if (strcmp(symbolTable[i].name, name) == 0) {
            return i;
        }
    }
    return -1; // Symbol not found
}

int main() {
    addSymbol("E");
    addSymbol("E'");
    addSymbol("T");
    addSymbol("T'");
    addSymbol("F");
    addSymbol("(");
    addSymbol(")");
    addSymbol("+");
    addSymbol("*");
    addSymbol("i");

    // Example: Searching for a symbol
    const char* symbolToFind = "F";
    int index = findSymbol(symbolToFind);
    if (index != -1) {
        printf("Symbol '%s' found at index %d\n", symbolToFind, index);
    } else {
        printf("Symbol '%s' not found\n", symbolToFind);
    }

    // You can add more symbols and attributes as needed

    return 0;
}
