#include "stack.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>
#include <string.h>

/**
 * Initializes a stack.
 * @param capacity - max amount of elements the stack can hold
 * @param type - the type of element the stack holds
 * @return stack - a pointer to an allocated and initialized stack
 */
Stack *st_init(int capacity, St_Type type) {
	Stack *stack = malloc(sizeof(Stack));
	stack->type = type;	
	stack->data = malloc(capacity * sizeof(St_Element));
	stack->type_size = sizeof(St_Element);
	stack->capacity = capacity;
	stack->size = 0;

	return stack;
}

/**
 * Frees any memory associated with a stack.
 * @param stack - a pointer to the stack to free
 */
void st_free(Stack *stack) {
	free(stack->data);
	free(stack);
}


/**
 * Checks if a stack is empty.
 * @param stack - a pointer to the stack to check
 * @return 0 if it is empty, otherwise 1
 */
int st_is_empty(Stack *stack) {
	return stack->size == 0;
}

/**
 * Doubles the capacity of the stack, copying all elements over and freeing
 * the old stack data.
 * @param stack - a pointer to the stack that needs doubled
 */
void st_double_cap(Stack *stack) {
	int new_cap = stack->capacity * 2;
	St_Element *new_data = malloc(new_cap * stack->type_size);

	memcpy(new_data, stack->data, stack->size * stack->type_size);

	stack->capacity = new_cap;
	free(stack->data);
	stack->data = new_data;
}

/**
 * Peeks at the top element of a stack.
 * @param stack - a pointer to the stack to peek
 * @param output - a pointer to write the peeked element to
 */
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

/**
 * Pops the top element off the stack, removing it.
 * @param stack - a pointer to the stack to pop
 * @param output - a pointer to write the popped element to
 */
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

/**
 * Pushes an element onto the stack.
 * @param stack - a pointer to the stack to push to
 * @param element - the element to push onto the stack
 */
void st_push(Stack *stack, St_Element element) {
	if (stack->size == stack->capacity) {
		st_double_cap(stack);
	}

	stack->data[stack->size] = element;
	stack->size++;
}
