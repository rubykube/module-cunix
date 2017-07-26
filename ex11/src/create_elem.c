#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/vm_filler.h"


elem_t* create_elem()
{
    char element[MAX_ELEM_HEIGTH][MAX_ELEM_WIDTH];
    int i, j, maxi = -1, maxj = -1;
    int flag = 0;
    int random[7];
    int count = 0;
    int percent = 30;
    for ( i = 0; i < MAX_ELEM_HEIGTH; i++)
        for( j = 0; j < MAX_ELEM_WIDTH; j++)
            element[i][j] = '.';
    element[0][0] = '*';
    element[0][1] = '*';

    /*                                                                                    *
     * the smallest element = "**"                                                        *
     * chance of generating next '*' in a column ~ 60%, 56%, 50%, 43%, 34%, 20%, 3%       *
     * chance of generating first element in each next row always 70% 60% 45% 35%         */
   for (i = 0; i < MAX_ELEM_HEIGTH; i++)
    {
        j = 0;
        for ( count = 101; count >= 40; count -= 10)
        {
            random[j] = 1 + rand() % count;
            j++;
        }

            for ( j = 0; j < MAX_ELEM_WIDTH; j++)
                {
                    if (i == 0)
                    {
                        if ( j == 5)
                            break;
                        else if ( random[j]  > 40)
                        {
                            element[i][j + 2] = '*';
                        }
                        else
                        break;
                    }
                    else if (j == 0)
                    {
                        if ( random[j] > percent)
                            element[i][j] = '*';
                        else
                        {
                            flag = 1;
                            break;
                        }
                    }
                         else if ( random[j] > 40)
                            element[i][j] = '*';
                            else break;
                }
                if (flag == 1)
                break;
            percent += 5;
   }

    for ( i = 0; i < MAX_ELEM_HEIGTH; i++)
    {
        for ( j = 0; j < MAX_ELEM_WIDTH; j++)
        {
            if ( element[i][j] == '*')
              {
                    if ( maxi < i)
                    maxi = i;
                    if (maxj < j)
                    maxj = j;
                }
        }
    }
    maxi += 1;
    maxj += 1;

    elem_t *elem = (elem_t*)malloc (sizeof(elem_t));
    elem->h = maxi;
    elem->w = maxj;
    elem->array = (char**)malloc(maxi * sizeof(char*));

    for (i = 0; i < maxi; i++)
        elem->array[i] = (char*)malloc(maxj * sizeof(char));


    for ( i = 0; i < maxi; i++)
        for ( j = 0; j < maxj; j++)
            elem->array[i][j] = element[i][j];


    return elem;
}
