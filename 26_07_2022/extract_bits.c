#include <stdio.h>

int main (void)
{
	int num = 0xca,num_bits = 3,pos = 2;
	printf ("Num : %d\n",num);
	num = (num & (((1<<num_bits)-1) << num_bits)) >> num_bits;
	printf ("Num : %d\n",num);
	return 0;
}
