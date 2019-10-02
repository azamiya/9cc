#include <stdio.h>
#include <stdlib.h>

typedef enum {
	TK_NUM
} TokenKind;

typedef struct Token Token;

struct Token {
	TokenKind kind;
};

Token *tokenize(char *p){
	Token head;
	return head;
};

int main(int argc, char **argv) {
	if (argc != 2) {
		fprintf(stderr, "引数の個数が正しくありません\n");
		return 1;
  	}

	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main:\n");
	token = tokenize(argv[1]);

	char *p = *(argv + 1);
	printf("	mov rax, %ld\n", strtol(p, &p, 10));
	while(*p) {
		if(*p == '+') {
			p++;
			printf("	add rax, %ld\n", strtol(p, &p, 10));
			continue;
		};

		if(*p == '-') {
			p++;
			printf("	sub rax, %ld\n", strtol(p, &p, 10));
			continue;
		};

		return 1;
	};
	printf("	ret\n");
	return 0;
}