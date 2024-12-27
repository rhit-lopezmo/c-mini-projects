#include "stack.h"
#include <stdio.h>

void st_print(Stack *st) {
	printf("current items: [");
	
	for (int i = 0; i < st->size; i++) {
		int item = st->data[i].i;
		printf("%d ", item);
	}
	
	printf("]\n\n");
}

void st_char_print(Stack *st) {
	printf("current items: [");
	
	for (int i = 0; i < st->size; i++) {
		char item = st->data[i].i;
		printf("'%c' ", item);
	}
	
	printf("]\n\n");
}

int main(void) {
	Stack *int_st = st_init(5, ST_INT);

	printf("init size: %d\n", int_st->size);
	printf("init capacity: %d\n", int_st->capacity);
	printf("init type size: %zu\n\n", int_st->type_size);


	// test if it fails when popping empty stack
	int failed = 0;
	st_pop(int_st, &failed);
	printf("failed to pop when empty? %s\n\n", failed == 0 ? "true" : "false");


	// test adding a single element then popping it
	int item = 1;
	st_push(int_st, (St_Element)item);
	printf("size after push #1: %d\n", int_st->size);
	int first_ele;
	st_pop(int_st, &first_ele);
	printf("element popped: %d\n", first_ele);
	printf("size after pop #1: %d\n\n", int_st->size);

	// test adding to limit and that cap doubles
	for (int i = 0; i < 5; i++) {
		int item = i;
		st_push(int_st, (St_Element)item);

		int top;
		st_peek(int_st, &top);
		printf("added %d to stack\n", top);
	}

	// show current elements
	st_print(int_st);	

	// add 1 more to see if capacity grows correctly
	int one_more = 5;
	printf("capacity before: %d\n",int_st->capacity);
	st_push(int_st, (St_Element)one_more);
	printf("current size: %d\n", int_st->size);
	printf("current cap: %d\n", int_st->capacity);
	st_print(int_st);

	st_free(int_st);

	// TESTING CHAR STACK
	printf("========================\n");
	printf("TESTING CHAR STACK\n");


	// intialize char stack
	Stack *char_st = st_init(5, ST_CHAR);

	// check init
	printf("init size: %d\n", char_st->size);
	printf("init capacity: %d\n", char_st->capacity);
	printf("init type size: %zu\n\n", char_st->type_size);

	// test adding a single element then popping it
	char char_ele = 'a';
	st_push(char_st, (St_Element)char_ele);
	printf("size after push #1: %d\n", char_st->size);
	char char_top;
	st_pop(char_st, &char_top);
	printf("element popped: %c\n", char_top);
	printf("size after pop #1: %d\n\n", char_st->size);

	// test adding to limit and that cap doubles
	for (char i = 'a'; i < 'e'; i++) {
		char item = i;
		st_push(char_st, (St_Element)item);

		char top;
		st_peek(char_st, &top);
		printf("added %c to stack\n", top);
	}

	// show current elements
	st_char_print(char_st);	

	// add 1 more to see if capacity grows correctly
	char one_more_char = 'e';
	printf("capacity before: %d\n",char_st->capacity);
	st_push(char_st, (St_Element)one_more_char);
	printf("current size: %d\n", char_st->size);
	printf("current cap: %d\n", char_st->capacity);
	st_char_print(char_st);

	st_free(char_st);


	return 0;
}
