#include <stdio.h>

int F(int x)
{
	printf("x=%d\n", x);
	if (0 == x) {
		return 0;
	} else if (0 < x) {
		return (2 * F(x - 1) + x * x);
	}
}

void main(int argc, char *argv[])
{
	printf("F(1)=%d, F(2)=%d, F(3)=%d\n", F(1), F(2), F(3));
}
