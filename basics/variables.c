/*
Types of variables in C:
primitive: int, float, char, double, string(char*) 
*/
#include<stdio.h>

int main(void){
    // declaring(giving identifier) and assigning a variable
    int integer=21;     
    float floatingpt=21.1;
    double doublefloat=21.11;
    char character='A';
    char * string="Hello There";


    // to print a variable, we need a format specifier and identifier
    printf("%d\n", integer);
    printf("%f\n", floatingpt);
    printf("%lf\n", doublefloat);
    printf("%c\n", character);
    printf("%s\n", string); 
    printf("%d\n", (int)floatingpt); // c automatically converts between numeric types whenever asked
    printf("%llu\n", sizeof(string)); // print sizeof variables and datatypes

    // boolean type: value of conditional and boolean(&&, ||, !) statement
    printf("%d", 1>2);



    // dissecting printf("%format", var):  var is converted to binary and whatever value is represented for given datatype's format is printed  
    // for example: consider variable c
    printf("\nDissecting printf:\n");
    int hexval=0x40; // to store hex value

    printf("%x\n", hexval); // hexadecimal representation. o represents octal
    printf("%d\n", hexval); // give 64
    printf("%f\n", hexval); // gives 0.0000( no floating point representation for 0x40)
    printf("%c\n", hexval); // gives @

    return 0;
}