#include <stdio.h>

int main(){
    FILE *fp;
    if( (fp=fopen("FILE.txt","w")) == NULL){
        printf("Error creating file for Writing!\n");
        exit(1);
    }
    printf("Enter strings:\n");
    char ch[100]={};
    while(1){
        gets(ch);
        if(ch[0]==0)
            break;
        if( fputs(ch,fp) == EOF ){
            printf("Error writing file!\n");
            exit(1);
        }
        if( fputc('\n',fp) == EOF ){
            printf("Error printing new line!\n");
            exit(1);
        }
    }

    return 0;
}
