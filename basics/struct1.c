#include<stdio.h>

// generally declared globally to use it as a user defined type
// one potential problem with char* is that we won't be able to know the actual size occupied 
// 
struct student{
  char *name; 
  char *id; 
  char address[100];
  int total_marks;
}; 


// passing structure as a pointer: this saves stack memory space and allows modification in the function itself
void modify_marks(struct student * stu, int inflation){
    // cannot directly use . operator, there are two ways to access elements:
    (*stu).total_marks+=inflation; //dereferencing
    stu->total_marks+=inflation; //recommended way using arrow operator
}



int main(void){
    // creating and initializing variable for the structure
    struct student stu1={"John Doe Arthur Jr", "314324", "Elm Street", 345}; // order is important
 
    // another way of initializing in which we don't need to maintain order
    struct student stu2={.name="Sam",.id="43434", .total_marks=213,.address="elm street"};


    modify_marks(&stu1, 100); // passing reference to struct variable

    printf("\nStudent Details:\n");
    printf("\nName: %s", stu1.name);
    printf("\nid: %s", stu1.id);
    printf("\naddress: %s", stu1.address);
    printf("\nMarks: %u", stu1.total_marks);

    // both the sizeof will give same result. It won't be the actual size though as we've used pointers
    printf("\nSize of student type: %u", sizeof(struct student));
    printf("\nSize of student variable: %u",sizeof(stu1));

    // copying one struct variable to othe directly copies everything and makes a new copy in memory(given same type)  
    struct student stu_new=stu1;

    return 0;
}

