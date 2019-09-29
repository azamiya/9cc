#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv) {
  printf("+ is %d\n", '+');
  printf("- is %d\n", '-');
  printf("* is %d\n", '*');
  printf("/ is %d\n", '/');
  printf("a is %d\n", 'a');
  printf("'4' is %d\n", '4');
  printf("'5' is %d\n", '5');
  printf("'9' is %d\n", '9');
  printf("'.' is %d\n", '.');
  if (argc != 2) {
    fprintf(stderr, "引数の個数が正しくありません\n");
    return 1;
  }

  printf("argv is %p\n", argv);
  printf("*argv[0] is %d\n", *argv[0]);
  printf("argv[0][1] is %c\n", argv[0][1]);
  printf("sizeof(argv[0][1]) is %ld\n", sizeof(argv[0][1]));
  printf("argv[0][2] is %c\n", argv[0][2]);
  printf("argv[0][3] is %c\n", argv[0][3]);
  printf("argv[0][4] is %c\n", argv[0][4]);
  printf("argv[0][5] is %c\n", argv[0][5]);
  printf("argv[0][6] is %c\n", argv[0][6]);
  printf("argv[0][7] is %c\n", argv[0][7]);
  printf("argv[0][8] is %c\n", argv[0][8]);
  printf("argv[0][9] is %c\n", argv[0][9]);
  printf("*argv[1] is %d\n", *argv[1]);
  printf("sizeof(*argv[0]) is %ld\n", sizeof(*argv[0]));
  printf("'.' is %ld\n", sizeof('.'));
  printf("sizeof(argv[0][1]) is %ld\n", sizeof(argv[0][1]));
  printf("&*argv[0] is %p\n", &*argv[0]);
  printf("&argv[0][1] is %p\n", &argv[0][1]);
  printf("&argv[0][2] is %p\n", &argv[0][2]);
  printf("argv[0][2] is %d\n", argv[0][2]);
  printf("*(&argv[0][2]) is %d\n", *(&argv[0][2]));
  printf("*(&argv[0][2]) is %c\n", *(&argv[0][2]));
  printf("&argv[0][3] is %p\n", &argv[0][3]);
  printf("&argv[0][4] is %p\n", &argv[0][4]);
  printf("&argv[0][5] is %p\n", &argv[0][5]);
  printf("&argv[0][6] is %p\n", &argv[0][6]);
  printf("&argv[0][7] is %p\n", &argv[0][7]);
  printf("&argv[0][8] is %p\n", &argv[0][8]);
  printf("&argv[0][9] is %p\n", &argv[0][9]);
  printf("&argv[0][10] is %p\n", &argv[0][10]);
  printf("&argv[0][11] is %p\n", &argv[0][11]);
  printf("&*argv[1] is %p\n", &*argv[1]);
  printf("sizeof(argv) is %ld\n", sizeof(argv));
  printf("**argv is %d\n", **argv);
  printf("argv[0][0] is %d\n", argv[0][0]);
  printf("argv[0][1] is %d\n", argv[0][1]);
  printf("*argv is '%s'\n", *argv);
  printf("argv[0] is '%s'\n", argv[0]);
  printf("*argv[0] is %d\n", *argv[0]);
  printf("argv[1] is '%s'\n", argv[1]);
  printf("*argv[1] is %d\n", *argv[1]);
  printf("(&*argv[1]) is %p\n", &*argv[1]);
  printf("(&**argv) is %p\n", &**argv);
  printf("sizeof(**argv) is %ld\n", sizeof(**argv));
  printf("sizeof(&argv) is %ld\n", sizeof(&argv));
  printf("sizeof(*argv) is %ld\n", sizeof(*argv));
  printf("sizeof(argv[0]) is %ld\n", sizeof(argv[0]));
  printf("sizeof(argv[0][0]) is %ld\n", sizeof(argv[0][0]));
  printf("sizeof(*argv[1]) is %ld\n", sizeof(*argv[1]));
  printf("strlen(*argv[0]) is %ld\n", strlen(*argv));

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
      printf("p[0] is '%d'\n", p[0]);
      printf("p[1] is '%d'\n", p[1]);
      printf("p[2] is '%d'\n", p[2]);
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