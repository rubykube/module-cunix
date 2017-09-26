---
date: 2016-10-09T17:14:35+02:00
title: ex07
---
## Linked list

### Objectives
* Learn about data structures
* Implement the linked list data structure

### Actions
* Read an article about linked list : `https://en.wikipedia.org/wiki/Linked_list `
![lists](http://i.stack.imgur.com/xsmmq.png)

* Go to the course directory `cd cep/courses/cunix/ex07/`
* Read carefully the file `include/linked_list.h` you will need to implement the prototype described here
```c
 typedef struct node {
   void         *data;
   struct node  *next;
 }              node_t;
```

* Create and Destroy will malloc and free the linked list.
```c
node_t  *list_create(void *data);
void    list_destroy(node_t **head, void (*fp)(void *data));
```
* Push and unshift will respectively add an element by the end and begining
```c
void    list_push(node_t **head, void *data);
void    list_unshift(node_t **head, char *key, void *data);
```

* Those functions will remove elements by the end, begining and by a pointer;
```c
void    *list_pop(node_t **head);
void    *list_shift(node_t **head);
void    *list_remove(node_t **head, node_t *ptr);
```

* You can visit an entire list and apply a function fp
```c
void    list_print(node_t *head);
void    list_visitor(node_t *head, void (*fp)(void *data));
```

* Create a file called  `src/linked_list.c`. It should implement the functions above
* Use `make debug` to test your program for memory leaks and errors
* Enter `make test` and see if your program works properly

### Bonus
 * Write stress tests for memory leaks
 * Add valgrind and run your code without errors

### Docs
* `en.wikipedia.org/wiki/Linked_list`
* `cslibrary.stanford.edu/103/LinkedListBasics.pdf`
* `www.cs.cmu.edu/~adamchik/15-121/lectures/Linked%20Lists/linked%20lists.html`
