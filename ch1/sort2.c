#include <stdio.h>
#define ARRAY_SIZE 1000
#define MAXKNUM	500

void MaoPaoSort(int *localArray, int MaxKnum)
{
	int subscript, sortTimes;
	for (sortTimes = 0; sortTimes < MaxKnum - 1; sortTimes++) {
		for (subscript = 1; subscript < MaxKnum - sortTimes; subscript++) {
			if (localArray[subscript] > localArray[subscript - 1]) {
				int temp;
				temp = localArray[subscript];
				localArray[subscript] = localArray[subscript - 1];
				localArray[subscript - 1] = temp;
			}
		}
#if 0
		printf("NO %d sort:", sortTimes); 
		int prtCnt;
		for (prtCnt = 0; prtCnt < MaxKnum; prtCnt++) {
			printf("%d ", localArray[prtCnt]);
		}
		printf("\n"); 
#endif
	}
}

int sortK(int *array, int arraySize, int MaxKnum)
{
	if (array == NULL || arraySize <= 0 || MaxKnum <= 0) {
		return -1;
	}

	// assign MaxKnum number in localArray
	int localArray[MaxKnum];
	int assignCnt;
	for (assignCnt = 0; assignCnt < MaxKnum; assignCnt++) {
		localArray[assignCnt] = array[assignCnt];
	}
	
	// sort localArray
	MaoPaoSort(localArray, MaxKnum);

	// get remain number in array add to in localArray for sort
	for (assignCnt = MaxKnum; assignCnt < arraySize; assignCnt++) {
		if (array[assignCnt] > localArray[MaxKnum - 1]) {
			int temp = 0;
			temp = array[assignCnt];
			array[assignCnt] = localArray[MaxKnum - 1];
			localArray[MaxKnum - 1] = temp;
			MaoPaoSort(localArray, MaxKnum);
		}
	}

	return localArray[MaxKnum - 1]; 
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
