#include<stdio.h>
/*
 Control statements in c are: switch, if else
                              for, while, do-while
                              break; continue;  
*/


int main(void){

    // Note: can chain any number of variable conditions in for statement
    for(int i=1,j=2, k=3; i<50,j<50,k<50; i++, j*=2, k*=2.5){
        printf("%d, %d, %d \n", i,j,k);    
    }

    return 0;
}