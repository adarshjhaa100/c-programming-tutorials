#include<stdio.h>

/*FILE* : variable of this type holds all the information of about File I/O. FILE* is also called "Stream"
which is used to steam data in/out from the program

C has some special predefined streams(all of these are FILE* vars):
stdout: pointer to destination for output, in this case the destination is console 
stdin: source of input, in this case its generally keyboard 
stderr: this is to output errors and warning messages and by default outputs to console
stderr can be redirected to other output target using freopen
*/

void read_textfile_characterwise(char * fname){
    FILE *fptr=fopen(fname, "r");
    char cpos;
    if(fptr==NULL){
        // always check for null file pointers
        return;
    }
    // each file ends with a special character EOF
    while((cpos=fgetc(fptr))!=EOF){
        printf("%c", cpos);
    }

    fclose(fptr); // Always remeber to close file which will deallocate memory
}

void read_textfile_linewise(char * fname){
    int lpos=0;
    FILE*fptr=fopen(fname,"r");
    char linebuff[1024];   // reads a line whose max allowed chars is 1023(one char for NULL)

    if(fptr==NULL){
        // always check for null file pointers
        return;
    }
    // fgets() is used to read line by line(each line can have max sizeof(linebuff) chars). it also terminates any line with \n automatically
    // linebuff is the target of data
    // loop ends when last line is NULL(or EOF)
    while(fgets(linebuff, sizeof linebuff, fptr)!=NULL){
        printf("%d: %s",lpos+1, linebuff);
        lpos++;
    }

    fclose(fptr);

}

void read_textfile_formattedip(char * fname){
    FILE *fptr=fopen(fname,"r");
    char linebuff[1024];
    int val1, val2;
     if(fptr==NULL){
        // always check for null file pointers
        return;
    }
    // 2 ways to read formatted input:1. fscanf(), 2. fgets()->sscanf()
    // fscanf can read directly using format 
    while((fscanf(fptr, "%s %d %d", linebuff,&val1, &val2))!=EOF){
        printf("\n%s:(%d,%d)\n",linebuff, val1, val2 );
    }

    fclose(fptr);
    
    fptr=fopen(fname,"r");
    // fgets()->sscanf(): use this method for files that are error prone
    while((fgets(linebuff,1024,fptr))!=NULL){
        int a, b;
        char c[50];
        sscanf(linebuff,"%s %d %d", c,&a,&b);
    }
    
    fclose(fptr);
}

// can write to file using fputc(), fputs(), fprintf()
void write_textfile(){
    FILE* fptr=fopen("data/new_writefile.txt","w");
    char cput='T';  
    char * sput="Hello There!";
    
    fputc(cput, fptr);
    fputc('\n',fptr);

    fputs(sput,fptr);
    fputc('\n',fptr);
    fprintf(fptr, "%s->(\'%c\')\n",sput,cput);

    fclose(fptr);

}

void write_binfile(){
    // We've intentionally used unsigned char here(they occupies 1 byte space)

    FILE *fptr=fopen("data/binfile.bin","wb"); // mode=wb instead of plain "w"
    // for wrting/reading from binary file we use fwrite(), fread() instead of functions like getc(), putc() etc. 
    
    unsigned char buff[]={'A','V','E','D'}; 
    // second param: sizeof single character, third: no of chars
    fwrite(buff,sizeof(unsigned char), sizeof(buff), fptr);

    fclose(fptr);
}

void read_binfile(){
    FILE *fptr=fopen("data/binfile.bin","rb");
    unsigned char rd;

    // fread returns 0 when EOF else returns >0
    while(fread(&rd,sizeof(unsigned char),1,fptr)>0){
        printf("%c ", rd);
    }

    fclose(fptr);
}

void binfile_serialisation_req(){
    // note that we've used unsigned char to read and write data in binary files in the functions write_binfile(), read_binfile()
    // this is because storage of binary data depends on architecture of the system. e.g. consider the hex value below
    int hexval=0x123456;

    FILE *fptr=fopen("data/serial_req.bin","wb");

    fwrite(&hexval, sizeof(int), 1, fptr);  //actually the text will be stored as: 56 34 12 00 which is opposite order

    // This is a reason that we should use serialization(maintain order of data) while transfering binary data from one source to another 
    // For serialization, we can ensure that we take care of the order and format
    // we can separate each byte using the code below and store them as character
    int num=0x00123456;
    int andby=0x000000FF;

    for(int i=0;i<4;i++)
    {
        
        printf("\n%c\n", (num&andby)>>(i*8));
        andby=andby<<8;
    }


    fclose(fptr);

}


int main(){
    // the below 2 statements are idenetical
    printf("\nHello, World\n");
    fprintf(stdout, "\nHello World\n");

    // In C files are categorized into: Text File and Binary File
    // Text File: allows significant translation of data e.g. storing endline
    // to read a text file: we need to open file in read mode "r"
    // read_textfile_characterwise("arrays1.c");

    // read_textfile_linewise("arrays1.c");

    // read_textfile_formattedip("data/formatted.txt");

    // write_textfile();

    // write_binfile();
    
    // read_binfile();

    // binfile_serialisation_req();

     int num=0x00123456;
    int andby=0x000000FF;

    for(int i=0;i<4;i++)
    {
        
        printf("\n%c\n", (num&andby)>>(i*8));
        andby=andby<<8;
    }

    

    return 0;
}