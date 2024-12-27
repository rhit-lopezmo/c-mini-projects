#ifndef STACK_H
#define STACK_H
#include <stddef.h>

typedef enum {
	ST_CHAR,
	ST_INT,
	ST_LONG,
	ST_FLOAT,
	ST_DOUBLE,
	ST_POINTER
} St_Type;

typedef union {
	char c;
	int i;
	long l;
	float f;
	double d;
	void *ptr;
} St_Element;

typedef struct {
	St_Element *data;
	size_t type_size;
	St_Type type;
	int capacity;
	int size;
} Stack;

Stack *st_init(int capacity, St_Type type); 
void st_free(Stack *stack);
int st_is_empty(Stack *stack);
void st_peek(Stack *stack, void *output);
void st_pop(Stack *stack, void *output);
void st_push(Stack *stack, St_Element element);

#endif
