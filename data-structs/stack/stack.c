#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

Stack *st_init(int capacity, St_Type type) {
	Stack *stack = malloc(sizeof(Stack));
	stack->type = type;	
	stack->data = malloc(capacity * sizeof(St_Element));
	stack->type_size = sizeof(St_Element);
	stack->capacity = capacity;
	stack->size = 0;

	return stack;
}

void st_free(Stack *stack) {
	free(stack->data);
	free(stack);
}

int st_is_empty(Stack *stack) {
	return stack->size == 0;
}

void st_double_cap(Stack *stack) {
	int new_cap = stack->capacity * 2;
	Stack *new_st = st_init(new_cap, stack->type_size);
	new_st->size = stack->size;
	
	for (int i = 0; i < stack->size; i++) {
		new_st->data[i] = stack->data[i];
	}

	st_free(stack);

	stack = new_st;
}

void st_peek(Stack *stack, void *output) {
	if (st_is_empty(stack)) {
		printf("error in st_peek: tried to peek when stack was empty\n");	
		return;
	}

	switch (stack->type) {
		case ST_CHAR:
			*((char *)output) = stack->data[stack->size - 1].c;
			break;
		case ST_INT:
			*((int *)output) = stack->data[stack->size - 1].i;
			break;
		case ST_LONG:
			*((long *)output) = stack->data[stack->size - 1].l;
			break;
		case ST_FLOAT:
			*((float *)output) = stack->data[stack->size - 1].f;
			break;
		case ST_DOUBLE:
			*((double *)output) = stack->data[stack->size - 1].d;
			break;
		case ST_POINTER:
			output = stack->data[stack->size - 1].ptr;
			break;
		default:
			printf("error in st_peek: unknown element type\n");
			return;
	}
}

void st_pop(Stack *stack, void *output) {
	if (st_is_empty(stack)) {
		printf("error in st_pop: tried to pop when stack was empty\n");	
		return;
	}

	switch (stack->type) {
		case ST_CHAR:
			*((char *)output) = stack->data[stack->size - 1].c;
			break;
		case ST_INT:
			*((int *)output) = stack->data[stack->size - 1].i;
			break;
		case ST_LONG:
			*((long *)output) = stack->data[stack->size - 1].l;
			break;
		case ST_FLOAT:
			*((float *)output) = stack->data[stack->size - 1].f;
			break;
		case ST_DOUBLE:
			*((double *)output) = stack->data[stack->size - 1].d;
			break;
		case ST_POINTER:
			output = stack->data[stack->size - 1].ptr;
			break;
		default:
			printf("error in st_pop: unknown element type\n");
			return;
	}

	stack->size--;
}

void st_push(Stack *stack, St_Element item) {
	if (stack->size == stack->capacity) {
		st_double_cap(stack);
	}

	stack->data[stack->size] = item;
	stack->size++;
}
