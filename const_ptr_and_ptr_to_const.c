/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    const int a =10;
    int b =20;
    int c =30;
    const int *ptr_to_const = &b;
    int * const const_ptr =&c;
    b =200; // b is nt a const , so t can change value 
   // *ptr_to_const = 2000;//however, b value cannt be changed through ptr_to_const --this lines throws error 
    ptr_to_const = &c; // yes the ptr_to_const can change pointig mem location --this lne is OK 
    printf("B =%d\n",b);
    *const_ptr = 3000;
    const_ptr = &b ;//put errror because it  read only variable and it constant;y point to only one mem_loc (C) not other variable_address
    printf("C = %d\n",c);

    return 0;
}
