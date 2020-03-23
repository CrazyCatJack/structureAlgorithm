// SPDX-License-Identifier: GPL-2.0-only
/*
 * sort1.c
 *
 * Copyright (C) 2020 CrazyCatJack
 */

#include <stdio.h>
#define ARRAY_SIZE 1000
#define MAXKNUM	500

int sortK(int *array, int arraySize, int MaxKnum)
{
	if (array == NULL || arraySize <= 0 || MaxKnum <= 0) {
		return -1;
	}

	int subscript, sortTimes;
	for (sortTimes = 0; sortTimes < arraySize - 1; sortTimes++) {
		for (subscript = 1; subscript < arraySize - sortTimes; subscript++) {
			if (array[subscript] > array[subscript - 1]) {
				int temp;
				temp = array[subscript];
				array[subscript] = array[subscript - 1];
				array[subscript - 1] = temp;
			}
		}
#if 0
		printf("NO %d sort:", sortTimes); 
		int prtCnt;
		for (prtCnt = 0; prtCnt < arraySize; prtCnt++) {
			printf("%d ", array[prtCnt]);
		}
		printf("\n"); 
#endif
	}

	return array[MaxKnum - 1]; 
}

void main()
{
	int array[ARRAY_SIZE];
	int assignCnt;
	for (assignCnt = 0; assignCnt < ARRAY_SIZE; assignCnt++) {
		array[assignCnt] = assignCnt;
	}
	int K = sortK(array, ARRAY_SIZE, MAXKNUM);
	printf("K = %d\n", K);	
}
