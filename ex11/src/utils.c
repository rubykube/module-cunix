#include <stdio.h>
#include <stdlib.h>

void  fail(char *err, int code)
{
  dprintf(2, err);
  exit(code);
}

char        get_symbol(int i)
{
  char c[4] = {'@', '#', '*', '%'};
  return c[i];
}

int        get_color (int i)
{
  return i+1;
}


