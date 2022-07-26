#include <stdio.h>

int main(void)
{
	char arr[] = {1,2,3,4};
	int *ptr = (int *)arr;
	printf ("Address of ptr %p\n",ptr);
	(char*)ptr++;
	printf ("Address of ptr %p\n",ptr);
	printf ("Value of ptr = %d\n",*(char*)ptr);
	return 0;
}
