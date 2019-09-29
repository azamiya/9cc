#include <stdio.h>
#include <string.h>

int main(void) {
  char *str = "Hello World";
  printf("str is %s\n", str);
  printf("&str is %p\n", &str);
  int i;
  printf("ADDRESS --------- CHARACTER ----- SIZE ----- ASCII CODE\n");
  for(i = 0; i < strlen(str); i++) {
  	printf("%p -- %c ------------- %ld -------- %d\n", &str[i], str[i], sizeof(str[i]), *&str[i]);
  }
  return 0;
}