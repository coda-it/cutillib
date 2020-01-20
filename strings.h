#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int concat(char **str, int n, ...) {
  int strLen = 0;
  va_list args;

  va_start(args, n);
  for (int i = 0; i < n; i++) {
    char *s = va_arg(args, char *);
    strLen += strlen(s);
  }
  va_end(args);

  *str = malloc(strLen + 1);
  memset(*str, '\0', strLen + 1);

  va_start(args, n);
  int prevLen = 0;

  for (int i = 0; i < n; i++) {
    char *s = va_arg(args, char *);
    strcpy(*str + prevLen, s);
    prevLen = strlen(*str);
  }
  va_end(args);

  return strLen;
}
