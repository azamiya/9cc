#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv) {
  printf("+ is %d\n", '+');
  printf("- is %d\n", '-');
  printf("* is %d\n", '*');
  printf("/ is %d\n", '/');
  printf("a is %d\n", 'a');
  printf("'4' is %d\n", '4');
  printf("'.' is %d\n", '.');
  if (argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }

  printf("argv is %p\n", argv);
  printf("**argv is %d\n", **argv);
  printf("argv[0][0] is %d\n", argv[0][0]);
  printf("*argv is '%s'\n", *argv);
  printf("argv[0] is '%s'\n", argv[0]);
  printf("*argv[0] is %d\n", *argv[0]);
  printf("argv[1] is '%s'\n", argv[1]);
  printf("*argv[1] is %d\n", *argv[1]);

  char *p = argv[1];
  printf("-------\n");
  printf("*p is %d\n", *p);
  printf("p is '%s'\n", p);
  printf("&p is %p\n", &p);
  printf("-------\n");

  printf(".intel_syntax noprefix\n");
  printf(".global main\n");
  printf("main:\n");
  printf("  mov rax, %ld\n", strtol(p, &p, 10));

  printf("-------\n");
  printf("*p is %d\n", *p);
  printf("p is '%s'\n", p);
  printf("&p is %p\n", &p);
  printf("-------\n");

  char* q = argv[1];
  printf("=======\n");
  printf("q is '%s'\n", q);
  printf("*q is %d\n", *q);
  printf("&q is %p\n", &q);
  printf("=======\n");

  while (*p) {
    printf("-------\n");
    printf("*p is %d\n", *p);
    printf("&p is %p\n", &p);
    printf("p is '%s'\n", p);
    printf("-------\n");
    if (*p == '+') {
      printf("before p++, p is '%s'\n", p);
      printf("before p++, *p is %d\n", *p);
      printf("before p++, *p is %d\n", p[0]);
      printf("*p == '+' is %d\n", (*p == '+'));
      
      p++;
      printf("after p++, p is '%s'\n", p);
      printf("  add rax, %ld\n", strtol(p, &p, 10));
      printf("*p is %d\n", *p);
      printf("&p is %p\n", &p);
      printf("p is '%s'\n", p);
      printf("-------\n");
      continue;
    }

    if (*p == '-') {
      printf("before p++, p is '%s'\n", p);
      printf("before p++, *p is %d\n", *p);
      printf("before p++, p[1] is %d\n", p[1]);
      p++;
      printf("after p++, p is '%s'\n", p);
      printf("after p++, *p is %d\n", *p);
      printf("after p++, &p is %p\n", &p);
      printf("  sub rax, %ld\n", strtol(p, &p, 10));
      printf("*p is %d\n", *p);
      printf("&p is %p\n", &p);
      printf("p is '%s'\n", p);
      printf("-------\n");
      continue;
    }

    fprintf(stderr, "予期しない文字です: '%c'\n", *p);
    return 1;
  }

  printf("  ret\n");
  return 0;
}