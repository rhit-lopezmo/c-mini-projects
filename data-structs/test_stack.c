#include "stack.h"
#include <stdio.h>

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
	St_Element item;
	item.i = 1;
	st_push(int_st, item);
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

	printf("current items: [");
	for (int i = 0; i < 5; i++) {
		int item = int_st->data[i].i;
		printf("%d ", item);
	}
	printf("]\n\n");

	st_free(int_st);
	return 0;
}
