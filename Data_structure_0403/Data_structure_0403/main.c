#include <stdio.h>
#include <stdlib.h>

#include "linearList.h"

int main() {
	listType* myList;

	myList = createList(10);
	insertItem(myList, 0, 10);
	insertItem(myList, 1, 20);
	insertItem(myList, 2, 30);
	insertItem(myList, 3, 40);

	printList(myList);

	insertItem(myList, 0, 5);
	printList(myList);

	insertItem(myList, 2, 15);
	printList(myList);

	insertItem(myList, 6, 15);
	printList(myList);

	insertItem(myList, -1, 100);
	printList(myList);

	insertItem(myList, 8, 15);
	printList(myList);

	return 0;
}