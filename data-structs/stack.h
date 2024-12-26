#ifndef STACK_H
#define STACK_H

typedef struct {
	void *data;
	int type_size;
	int capacity;
	int size;
} Stack;

void st_init(Stack *stack); 
void *st_pop(Stack *stack);
void st_push(Stack *stack, void *item);
int st_empty(Stack *stack); // checks if stack is emptying, returning 1 if true or 0 if not

#endif
