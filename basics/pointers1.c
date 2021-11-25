#include<stdio.h>


int main(void){

    //pointer points to address of a variable
    int variable=10;
    int* ptrvar=&variable;
    int **ptrdouble=&ptrvar; // can chain pointers 

    printf("%x\n",ptrvar); // p is format for pointer address
    printf("%x\n",ptrdouble);

    printf("program will crash after assinging value to null ptr's location");
    
    int *ptrnull=NULL;              // null pointer, a special type of pointer that points to nothing
    *ptrnull= 32;                   // this is illegal as originally the pointer wasn't pointing to any location
    printf("hello");
    printf("Hello%xn", ptrnull);
    
    // sizeof any type of pointer is 8 bytes(for 64 bit system) or 4(for 32 bit systems)

    // Situations where its recommended to pass things by pointer:
    // 1. Need to save the modified values of the variable
    // 2. For variables occupying large space(such as structs). Thich saves memory space of stack  
    // Note: we do need to make sure of NULL pointers in memory 

    return 0;
}