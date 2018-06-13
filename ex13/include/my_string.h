#ifndef _STRING_H_
#define _STRING_H_
#include "filler.h"

#define BUF_SIZE 64

stream_t        *string_init();
stream_t        *string_create(char* str);
void            string_append(stream_t *ptr, char* str);
void            string_destroy(stream_t *str);

#endif