#include<stdio.h>
#include<string.h> // contains functions for string 


int main(void){

    // string is a sequence of characters, which is defined as:
    // the first one is a mutable string(we can modify its value), while second is ptr to a constant string which can't be modified
    char str_mut[]="hello there! you can change me";
    char *str_const="i'm a constant";

    //escape sequence:to add some special actions to string(like tab space, end line, "" etc)
    printf("This is a tab\t. this is endline\n this is doubld quote \"");

    // There are two ways in which languages store a string: 1. store the string alongwith length at the end 2.terminate string with a special character
    // C uses the second method where it store the character \0 at the end 

    // to print the length of the string, use:
    printf("\nString len:%u", strlen(str_mut));

    // copying a string by: char* str2=str will just make 2 pointers point at the same 
    // we need to copy element by element, make sure target string size is > that source
    // note: first string is the target
    strcpy(str_mut, str_const);

    printf("\n%s",str_mut);


    return 0;
}