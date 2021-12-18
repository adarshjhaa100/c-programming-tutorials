#include<stdio.h>
#include<stdarg.h>


void var_arglist(int nvars,...){
    va_list valist;
    
    va_start(valist, nvars);

    for(int i=0;i<nvars; i++){
        printf("var %d = %d\n", i, va_arg(valist,int));
    }

    va_end(valist);
}

int main(){
    
    var_arglist(5,2,3,4,5,1);
    return 0;
}