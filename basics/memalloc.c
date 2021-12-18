#include<stdio.h>
#include<string.h>
#include<stdlib.h> // for malloc

int main(){
    // result of malloc is a void * 
    int *ptrint=malloc(sizeof(int));    // allocate memory of size one integer
    *ptrint=23;

    int *ptrarr=malloc(sizeof(int)*10); // allocate memory to 10 elements of int array
    // generally we should clean garbage values in allocated array using memset(set all values to 0)
    memset(ptrarr, 0, sizeof(int)*10);

    *ptrarr=10;
    ptrarr[1]=12;

    // or we can use calloc which automatically clears array
    int *ptrarr2=calloc(sizeof(int), 10);


    // generally, we should check whether memory was successfully allocated using
    if((ptrarr=malloc(sizeof(int)*10))!=NULL)
        printf("\nNo Problem allocating array\n");


    // reallocate size of arr
    ptrarr=realloc(ptrarr, sizeof(int)*40); // the destination ptr is same in this case


    // free memory. Note: after this memory won't be accessible 
    free(ptrint);
    free(ptrarr);
    free(ptrarr2);
    return 0;

    
}