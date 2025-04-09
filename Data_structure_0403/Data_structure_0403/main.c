#include <stdio.h>
#include <stdlib.h>

#include "LinearList.h"
listType* SmTranspose(listType* org) {
	listType* tr;
	elementType o_item;

	tr = createList(org->size);
	for (int i = 0; i <= org->last; i++) {
		o_item = readItem(org, i);
		ordered_insertItem(tr, (elementType) { o_item.col, o_item.row, o_item.val });
	}
	return tr;
}

main() {
	listType* myList, *trans;

	myList = createList(20);

	ordered_insertItem(myList, (elementType) { 0, 2, 2 });
	ordered_insertItem(myList, (elementType) { 0, 6, 12 });
	ordered_insertItem(myList, (elementType) { 1, 4, 7 });
	ordered_insertItem(myList, (elementType) { 2, 0, 23 });
	ordered_insertItem(myList, (elementType) { 3, 3, 31 });
	ordered_insertItem(myList, (elementType) { 4, 1, 14 });
	ordered_insertItem(myList, (elementType) { 4, 5, 25 });
	ordered_insertItem(myList, (elementType) { 5, 6, 6 });
	ordered_insertItem(myList, (elementType) { 6, 0, 52 });
	ordered_insertItem(myList, (elementType) { 7, 4, 11 });

	printf("Original Martix\n");
	printList(myList);

	trans = SmTranspose(myList);

	printf("Transpose Martix\n");
	printList(myList);

/*ordered_insertItem(myList, 0, 10);
	ordered_insertItem(myList, 1, 20);
	ordered_insertItem(myList, 2, 30);
	ordered_insertItem(myList, 3, 40);

	insertItem(myList, 0, 10);
	insertItem(myList, 1, 20);
	insertItem(myList, 2, 30);
	insertItem(myList, 3, 40);

	printList(myList);

	ordered_insertItem(myList, 10);
	printList(myList);
	ordered_insertItem(myList, 15);
	printList(myList);
	ordered_insertItem(myList, 45);
	printList(myList);
	ordered_insertItem(myList, 100);
	printList(myList);

	insertItem(myList, 0, 5);
	printList(myList);

	insertItem(myList, 2, 15);
	printList(myList);

	insertItem(myList, 6, 45);
	printList(myList);

	insertItem(myList, -1, 100);
	printList(myList);

	insertItem(myList, 8, 100);
	printList(myList);
	*/
}