#include <stdio.h>

int main(){

    FILE *fp;

    if ( (fp=fopen("File.txt", "rb")) == NULL ){
        printf("Error Opening File for reading!\n");
        exit(1);
    }
    printf("String in file\n\n");

    while(1){
        char ch = fgetc(fp);
        if (feof(fp)==0){
            if (ferror(fp)==0){
                putchar(ch);
            }
            else{
                printf("Error!\n");
                exit(1);
            }
        }
        else{
            break;
        }
    }

    printf("\n\nPrinted in reverse form\n\n");

    if ( fseek(fp, 0, SEEK_END) != 0 ){
        printf("Error in fseek()\n");
        exit(1);
    }

    int length = ftell(fp)-1;

    for(length; length>=0; length--){

        if ( fseek(fp, length, SEEK_SET) != 0 ){
            printf("Error in fseek()\n");
            exit(1);
        }

        char ch = fgetc(fp);
        if (feof(fp)==0){
            if (ferror(fp)==0){
                putchar(ch);
            }
            else{
                printf("Error!\n");
                exit(1);
            }
        }
        else{
            break;
        }
    }
    return 0;
}
