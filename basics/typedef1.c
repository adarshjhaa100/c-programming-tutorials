#include<stdio.h>

/* 
typedef: also known as type aliases helps giving alias to datattypes
Generally declared globally so that all functions can access it
*/
typedef int newint; 
newint a=10;

// typedefs can be used to set type for user defined databases
typedef struct student{
    char*name;
    int age;
} stutype;

stutype stu1={.age=12, .name=13};

// generally we use typedef to give alias to anonymous structs
typedef struct {
    char * id;
    int marks;
} tchrtype;

// one use case where giving typedef to primitive datatype is useful. Suppose we have used float in many places
typedef float fl_type;
// changing the above line to: 
typedef long double fl_type; // this way we need to change only a single line

int main(){
    
    return 0;
}


