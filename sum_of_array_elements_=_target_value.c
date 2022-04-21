// Online C compiler to run C program online

#include <stdio.h>
int k;
int *find_target(int *num_arr,int tar_arg,int size_arg)
{
    int i,sum,j;
    static int res_arr[10];//using static for passing address of its value to main function
    for(i=0;i<size_arg-1;i++)    // to pick one element and check with other elements
    {
        for(j=i+1;j<size_arg;j++)  // j index useful to compare with prev ith index value
        {
         sum = num_arr[i] + num_arr[j];
        if(sum == tar_arg) //check sum of elements in array = target value is true or not
        {
            res_arr[k] = i; //it store the ith index
            k++;
            res_arr[k] = j; //it store the jth index
            k++;
        }
        }
    }
    return res_arr;
}

int main()
{
    int arr[] = {5,0,9,4},target = 9;
    int size,*ret=NULL, i;
    size = sizeof(arr)/sizeof(arr[0]); //Find no.of elements in arr[] 
    ret = find_target(arr,target,size); //to get more than 1 data from calling function
    for(i=0;i<k;i++)                    //To display all data b using loop
          printf("%d",*(ret+i));
    return 0;
}
