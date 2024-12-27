#include "lexer.h"
#include <stdio.h>

int main() {
    const char* source = "int main() { return 42; }";
    Lexer lexer;
    initLexer(&lexer, source);

    Token token;
    do {
        token = getNextToken(&lexer);
        printf("Token: Type = %d, Value = %s\n", token.type, token.value);
    } while (token.type != TOKEN_EOF);

    return 0;
}