#include<stdio.h>

// only if arr1 and arr2 point to elements of the same array
int no_of_elements_bw_ptrs(int* arr1, int *arr2){
    return arr2-arr1;
}

// sometimes, when type of variable passed is not known, we can use void ptr
// void ptr can be used to copy elements from one arr to another(bot same type) without the knowledge of the actual type of those arrays, sort arrays and more
// void ptr has few limitations:1.pointer arithmetic won't be applicable as we don't know the actual size of elements 2.     
int void_ptr_no_elements(void *ptr1, void *ptr2){
    return ptr2-ptr1;
}


int main(){

    int arr[]={10,20,30,40,9999};
    int *ptr1=&arr[1],*ptr2=&arr[4];
    
    printf("\nvalue of pointers: %x %x\n", ptr1, ptr2 ); // occupied 61fdf0 and 61fdf4 for the current execution 
    
    // we can subtract two pointers pointing to elements of the same array to find the number of elements between them  
    printf("\n# of Elements: %d\n", no_of_elements_bw_ptrs(ptr1, ptr2));

    // Array ptr eqivalence: arr[i]=*(arr+i)
    
    printf("\nno of elements in void *:%d\n", void_ptr_no_elements(ptr1, ptr2));

    return 0;
}

