#include<stdio.h>
#include<limits.h>
#include<float.h>

void signed_unsigned(){
    int int_var; // by default every datatype is signed, msb represents sign, range= -2^(n-1) to 2^(n-1)-1. This is represented in 2's complement
    unsigned int u_int_var; // all bits are used to represent magnitude, positive range of n bit unsigned=0 to 2^n-1
    int_var=-13; // FFFFFFF3(32 bit 2's complement)
    u_int_var=13; // 0000000D
    printf("\n%x\n", int_var); // %p format prints full hex
    printf("\n%x\n", u_int_var);
}

void scope_loop(){
    // special condition for scope of a variable
    for(int i=0;i<10;i++){
        int i=89; // this hides the i defined in the loop paranthesis
        // printf("\t%d\t", i); // will print "89" 10 times
    }
}

void long_short(){
    long int lint=22; // double of int's size
    long long int llint=32223; // same size as long in case of 64 bit systems, for 32 bits its double size of long
    unsigned long ulint=2332; // can mix unsigned with ulint

    // can find the limits for all integer based numbers in limits.h 
    printf("%lld\n", LLONG_MAX); // lld-> format specifier of Long long decimal 
    printf("%lld\n", CHAR_MAX);
    printf("%lld\n", LONG_MAX);
    printf("%lld\n", INT_MAX);
    printf("%lld\n", ULONG_MAX);
}


void float_double(){
    // floating point numbers are represented using IEEE 754( first bit is signed followed by exponent and mantisaa)
    printf("Representation of float for %lf: %x", 1.234,1.234);
    // limits for floating pt are specified in float.h and programmers should keep that in mind else there maybe some inconsistencies in values
    printf("\n%d", FLT_DIG);
    printf("\n%d", DBL_DIG);
    printf("\n%d", LDBL_DIG);
}

void type_suffix(){
    // Generally when we use a constant value, C automatically assigns the smallest possible type to it
    // we can force this behavior using suffix
    int isuffl=1234L; // long
    int isuffll=1234LL; // long long
    int isuff=1233U; // usigned

    // floating point consts have F and double has L
    float fnum=123L;
}

void hex_float(){
    // we can represent a hexadecimal float using
    double fx=0xa.1p4; // equivalent to 0x1010.0001p4, p4 is power 4. Base 10 number int double: (10+1*2^-4)*2^4=10.0625*16 
    printf("Scientific notation of %f is: %a",fx, fx);
    
}

int main(){

    // loop_scope();
    // signed_unsigned();
    // long_short();
    // float_double();
    hex_float();

    return 0;
}