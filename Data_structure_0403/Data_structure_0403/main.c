#include <stdio.h>
#include <stdlib.h>

#include "LinearList.h"
listType* ployadd(listType* f, listType* s) {
	listType* a;

	int i = 0;
	int j = 0;
	elementType f_item, s_item;

	a = createList(f->last + s->last + 2);

	while (i <= f->last && j <= s->last) {
		f_item = readItem(f, j);
		s_item = readItem(s, j);

		if (f_item.expo < s_item.expo) {
			ordered_insertItem(a, f_item);
			i++;
		}
		else if (f_item.expo == s_item.expo) {
			ordered_insertItem(a,
				(elementType) {
				(f_item.coef + s_item.coef), f_item.expo
			});
			i++; j++;
		}
		else {
			ordered_insertItem(a, f_item);
			j++;
		}

	}
	while (j <= s->last) {
		ordered_insertItem(a, readItem(s, j));
		j++;
	}
	return a;
}
//listType* SmTranspose(listType* org) {
//	listType* tr;
//	elementType o_item;
//
//	tr = createList(org->size);
//	for (int i = 0; i <= org->last; i++) {
//		o_item = readItem(org, i);
//		ordered_insertItem(tr, (elementType) { o_item.col, o_item.row, o_item.val });
//	}
//	return tr;
//}

main() {
	//polynomial

	listType* ploy1, *ploy2, *ploy3;

	ploy1 = createList(10);
	ordered_insertItem(ploy1, (elementType) { 4, 3 });
	ordered_insertItem(ploy1, (elementType) { 2, 1 });
	ordered_insertItem(ploy1, (elementType) { 1, 0 });
	printf("First Polynomial \n");
	printList(ploy1);

	ploy2 = createList(10);
	ordered_insertItem(ploy2, (elementType) { 3, 2 });
	ordered_insertItem(ploy2, (elementType) { 4, 1 });
	printf("Second Polynomial \n");
	printList(ploy1);

	ploy3 = ployadd(ploy2);
	printf("add Polynomial \n");
	printList(ploy3);

	destroyList(ploy1);

	/*listType* myList, *trans;

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
	printList(myList);*/

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