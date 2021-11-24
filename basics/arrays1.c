#include<stdio.h>


// passing arrays to function
// other ways: fn(int arr[]), fn(int arr[size]) etc
void sumArr(int *arr, int size){
    int sum=0;
    for(int i=0;i<size;i++)
        sum+=arr[i];
    
    arr[2]*=2; // manipulating the element will modify the actual array as we have pointer to the array

    printf("%d", sum);
}

// passing 2d arrays here we need the no of cols, other ways:(int arr[r][c]), (int (*arr)[3]) 
void sum2darr(int arr[][3], int row, int col){
    for(int i=0;i<row; i++){
       for(int j=0;j<col;i++)
        printf("(%d,%d)->%d", arr[i][j]); 
    } 
}


int main(void){
    
    int arr[5];   // define array with a fixed constant size
    arr[1]=10; // initialize values( by default every value in the array in 0) 
    
    int arrinit[]={2,3,40}; // define and initialize array with size 3, can explicitly mention size

    // out of bounds in array: after the given size of array, there are random values(which is not part of the array) which C lets us access.
    // therefore, its always necessary to store the take care of bounds
    // C by default doesn't tracks the size of array
    for(int i=0;i<10;i++){
        printf("(%d->%x)", i, arrinit[i]);
    }
    
    // 2d arr is stored in row major order
    // to access elements in row major array with (r,c) at posn (i,j) :i*c+j
    int arr2d[][3]={{0},{1},{2}}; // 2d array: here, we need to specify the second dimension(no of cols)

    // pointer to array: the array identifier is actually a pointer to array
    int *ptrarr=arr; // this is equivalent to ptrarr=&arr[0]

    return 0;
}

