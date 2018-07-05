#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "test.h"

int test_small()
{
	char *foo = (char *)halloc(20);
	assert(foo > (char *)0x0000000000000001);
	my_free(foo);
	foo = (char *) halloc(10000000000000000000u);
	assert(foo == NULL);
	my_free(foo);
  	foo = (char *) halloc(0);
	assert(foo == NULL);
  	my_free(foo);
	return 0;
}

int test_long()
{
	int **a = (int **)halloc(sizeof(int) * 10000);
	for (int i = 0; i < 1000; i++)
	{
		int *tmp = (int *)halloc(sizeof(int));
		*tmp = i;
		a[i] = tmp;
	}
	for (int i = 0; i < 1000; i++)
		my_free(a[i]);
  	my_free(a);
	return 0;
}

int main()
{
    test_small();
    test_long();
    return 0;
}

