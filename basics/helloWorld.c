/*Basic input output in C, with some datatypes explained*/
// preprocessor directive: compiler loads these in preprocessor phase( before actual compilation starts)
#include<stdio.h>   // containes preprocessor directives and function prototypes for common I/O needs

// to compile multiple files in a single executable, gcc file1, file2... Note!:there should be single main() in all files combined 
// to generate asm=> gcc -S filename.c
// to save intermediate files generated during compile time -save-temps=obj(saved in the same dir as executable)
// to display warning set -Wall -Wextra 

int main(void){
    printf("%s","\nHello World\n" );
    return 0;
}