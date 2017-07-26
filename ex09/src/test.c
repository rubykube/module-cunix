
#include "hash.h"

#define _GNU_SOURCE


#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include <string.h>

void test_func_noop(void *data)
{
  data;
}

int               test_create()
{
  hashtable_t *ht1 = hash_create(128);
  for (int i = 0; i < 128; i++)
    ht1->table[i] = NULL;

  hashtable_t *ht2 = hash_create(1);
  hashtable_t *ht3 = hash_create(10000);
  hashtable_t *ht4 = hash_create(0);
  assert(ht4 == NULL);

  hash_destroy(ht1, &test_func_noop);
  hash_destroy(ht2, &test_func_noop);
  hash_destroy(ht3, &test_func_noop);
  return 0;
}

int               test_hashfunc()
{
  assert(hash_func("Key1") == hash_func("Key1"));
  assert(hash_func("short_key") > 0);
  assert(hash_func("Key395784854211478885421154879865214458444444440") ==  hash_func("Key395784854211478885421154879865214458444444440"));
  assert(hash_func(NULL) == hash_func(NULL));
  assert(hash_func("middle_key_pratatapratata") > 0);
  assert(hash_func("long_key_pratatapratatapratatapratatapratatapratatapratatapratata") > 0);
  assert(hash_func("Key87") > hash_func("Key86"));
  assert(hash_func("K") != hash_func("k"));
  assert(hash_func("0") == hash_func("0"));

  return 0;
}

int test_hash_set()
{
  char        *key;
  char        *data;

  hashtable_t *ht = hash_create(128);

  hash_set(ht, "key1", "Valentine", &test_func_noop);
  hash_set(ht, "key2", "Andrey", &test_func_noop);
  hash_set(ht, "key3", "Dima", &test_func_noop);
  hash_set(ht, "key4", "Bohdan", &test_func_noop);
  hash_set(ht, "key5", "Maryna", &test_func_noop);
  hash_set(ht, "key6", "Galya", &test_func_noop);

  assert(strcmp(hash_get(ht, "key1"), "Valentine") == 0);
  assert(strcmp(hash_get(ht, "key2"), "Andrey") == 0);
  assert(strcmp(hash_get(ht, "key3"), "Dima") == 0);
  assert(strcmp(hash_get(ht, "key4"), "Bohdan") == 0);
  assert(strcmp(hash_get(ht, "key5"), "Maryna") == 0);
  assert(strcmp(hash_get(ht, "key6"), "Galya") == 0);

  assert(hash_get(ht, "key7") == NULL);

  hash_destroy(ht, &test_func_noop);
  return 0;
}

int test_large()
{
  char        *key;
  char        *data;

  data = "data";
  key = "key";
  hashtable_t *ht_large = hash_create(10000);

  for(int i = 0; i < 10000; i++)
  {
    hash_set(ht_large, key, data, &test_func_noop);
    data += i;
  }

  assert(strcmp(hash_get(ht_large, key), "data") == 0);

  hash_destroy(ht_large, &test_func_noop);

  return 0;

}

int main()
{
  assert(test_hashfunc() == 0);
  puts("test_hashfunc OK");

  assert(test_create() == 0);
  puts("test_create OK");

  assert(test_hash_set() == 0);
  puts("test_hash_set OK");

  assert(test_large() == 0);
  puts("test_large OK");

  return 0;
}
