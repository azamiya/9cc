#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
	printf(".intel_syntax noprefix\n");
	printf(".global main\n");
	printf("main:\n");
	printf("	mov rax, 5\n");
	printf("	add rax, 20\n");
	printf("	sub rax, 4\n");
	printf("	ret\n");
	return 0;
}