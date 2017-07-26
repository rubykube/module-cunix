#include <stdio.h>
#include <stdlib.h>

#include "vm_filler.h"

void textcolor(int attr, int fg, int bg)
{
  char command[13];

  sprintf(command, "%c[%d;%d;%dm", 0x1B, attr, fg + 30, bg + 40);
  printf("%s", command);
}

void          print_map(vmcore_t  *vm)
{
  int         n, m;

  n = vm->map.h;
  m = vm->map.w;
  int color;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      if (vm->map.array[i][j] != '.')
      {
        for(int l=0; l<vm->nbplayers; l++)
          if (vm->map.array[i][j] == vm->players[l]->symbol)
            color = vm->players[l]->color;
        textcolor(1, color, 0);
      }
      printf ("%c ", vm->map.array[i][j]);
      textcolor(0, 7, 0);
    }
    printf("\n");
  }
  printf("\n");
}

void print_matrix(int fd, char **array, int h, int w)
{
  int   pos = 0;
  char *buffer;

  buffer = (char*) malloc((w*h + h + 1) * sizeof(char));
  for (int i = 0; i < h; i++)
  {
    for (int j = 0; j < w; j++)
    {
      buffer[pos] = array[i][j];
      pos++;
    }
    buffer[pos] = '\n';
    pos++;
  }
  buffer[pos] = '\0';
  dprintf(fd, "%d %d\n%s", h, w, buffer);

  free(buffer);
  buffer = NULL;
}

void print (int fd, vmcore_t *vm)
{
  //printf("print func\n");
  dprintf(fd, "%c\n", vm->players[vm->turn]->symbol);
  print_matrix(fd, vm->map.array, vm->map.h, vm->map.w);
//  printf("print elem\n");
  print_matrix(fd, vm->current_elem->array, vm->current_elem->h, vm->current_elem->w);
}
