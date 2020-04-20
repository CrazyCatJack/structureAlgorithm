#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "QuickList.h"

#define BUCKET_NUM 10 //10 buckets
#define NUMBER_RANGE	3 // 0 - 999

void bucketSort2(int *inputArray, int num)
{
	QuickListNode_T qlArray[BUCKET_NUM];
	memset(qlArray, 0, BUCKET_NUM); 
	int cnt; 
	for (cnt = 0; cnt < BUCKET_NUM; cnt++) {
		qlArray[cnt] = QuickListCreateList();	
	}

	QuickListNode_T *tmp;
	int times;
	int divisor = 1;
	for (times = 0; times < NUMBER_RANGE; times++) {
		for (cnt = 0; cnt < num; cnt++) {
			tmp = QuickListCreateNode(&inputArray[cnt]);
			QuickListAddNodetoTail(tmp, alArray[inputArray[cnt] / divisor % 10]);	
		}
		divisor *= 10; 
			
	}	
}
