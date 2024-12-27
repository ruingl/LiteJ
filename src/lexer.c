#include "lexer.h"
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void initLexer(Lexer* lexer, const char* source) {
    lexer->start = source;
    lexer->current = source;
    lexer->line = 1;
}

int isIdentifierChar(char c) {
    return isalnum(c) || c == '_';
}

Token getNextToken(Lexer* lexer) {
    Token token;
    lexer->start = lexer->current;

    if (*lexer->current == '\0') {
        token.type = TOKEN_EOF;
        token.value = "";
        return token;
    }

    while (isspace(*lexer->current)) {
        if (*lexer->current == '\n') {
            lexer->line++;
        }
        lexer->current++;
    }

    if (isalpha(*lexer->current) || *lexer->current == '_') {
        while (isIdentifierChar(*lexer->current)) {
            lexer->current++;
        }
        int length = lexer->current - lexer->start;
        token.value = (char*)malloc(length + 1);
        strncpy(token.value, lexer->start, length);
        token.value[length] = '\0';

        token.type = TOKEN_IDENTIFIER;
        return token;
    }

    token.type = TOKEN_EOF;
    token.value = "";
    return token;
}