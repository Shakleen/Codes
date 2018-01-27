#include <stdio.h>

int main(){
    FILE *fp;
    //WRITING THE FILE
    if( (fp=fopen("FILE.txt","w")) == NULL ){
        printf("Error Opening File for writing!\n");
        exit(1);
    }
    printf("Please Input string for testing:\n");
    char str[1000]={};
    gets(str);
    char *p=str;
    while(*p){
        if( (fputc(*p++,fp)) == EOF ){
            break;
            exit(1);
        }
    }
    if( fclose(fp) == EOF ){
        printf("Error Closing File!\n");
        exit(1);
    }
    //READING THE FILE
    if( (fp=fopen("FILE.txt","r")) == NULL){
        printf("Error Opening File for Reading!\n");
        exit(1);
    }
    char ch=0;
    while( (ch=fgetc(fp)) != EOF){
        putchar(ch);
    }
    return 0;
}
