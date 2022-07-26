#include <stdio.h>
#define TOGGLE_BIT(num,pos) num = num ^ (0x1<<pos)

int main (void)
{
	int num = 13,pos = 2;
	TOGGLE_BIT (num,pos);
	printf ("After toggle %d bit num = %d\n",pos,num);
	return 0;
}
