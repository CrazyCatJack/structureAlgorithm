// SPDX-License-Identifier: GPL-2.0-only
/*
 *	bucketSort2.c
 *
 * Copyright (C) 2020  xuri
 */

/*
 * This file show how bucket sort running, it based on QuickList module
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "QuickList.h"

#define ARRAY_NUM	10
#define BUCKET_NUM 10 //10 buckets
#define NUMBER_RANGE	3 // 0 - 999

void bucketSort2(int *inputArray, int num)
{
	int divisor = 1;
	int cnt; 
	int *recvdata;
	int times = 0;
	QuickListNode_T *tmp = NULL, *tmp2 = NULL;
	QuickListNode_T *qlArray[BUCKET_NUM];


	/* initialize the qlArray */
	memset(qlArray, 0, BUCKET_NUM); 
	for (cnt = 0; cnt < BUCKET_NUM; cnt++) {
		qlArray[cnt] = QuickListCreateList();	
	}


	/* first time input array and create listnode add to qlArray */
	for (cnt = 0; cnt < num; cnt++) {
		tmp = QuickListCreateNode(&inputArray[cnt]);
		QuickListAddNodetoTail(qlArray[(inputArray[cnt] / divisor % 10)], tmp);
	}
	printf("after first time\n");	

	/* finish bucket sort */
	while (times < NUMBER_RANGE - 1) {
		divisor *= 10;
		for (cnt = 0; cnt < BUCKET_NUM; cnt++) {
			tmp = NULL;
			tmp2 = NULL;
			QuickList_for_each_entry_safe(qlArray[cnt], tmp, tmp2) {
				recvdata = QuickList_entry(int, tmp);
				if ((*recvdata / divisor % 10) != cnt) {
					QuickListDetachNode(qlArray[cnt], tmp);
					QuickListAddNodetoTail(qlArray[(*recvdata / divisor % 10)], tmp);
				}
			}
		}
		times++;
	}

	/* print array after bucket sort */
	printf("Start print array after bucket sort:\n");
	for (cnt = 0; cnt < BUCKET_NUM; cnt++) {
		QuickList_for_each_entry(qlArray[cnt], tmp) {
			recvdata = QuickList_entry(int, tmp);
			printf("%d ", *recvdata);
		}
	}
	printf("\n");
}

void main(int argc, char *argv[])
{
	int array[ARRAY_NUM] = {64, 8, 216, 512, 27, 729, 0, 1, 343, 125};
	bucketSort2(array, ARRAY_NUM);
}

