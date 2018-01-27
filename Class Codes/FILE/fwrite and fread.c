/*
Illustration of fwrite() and fread()
*/

#include <stdio.h>

int main(){
    //Declaring necessary variables
    int i=0, num[5]={};
    //Taking input
    printf("Enter 5 integer data:\n");
    for(i=0; i<5; i++){
        scanf("%d", &num[i]);
    }
    FILE *fp;
    //Opeing stream for writing into file
    //Error Checking fopen()
    if ( (fp=fopen("FILE.txt", "wb")) == NULL ){
        printf("Error Opening file for writing!\n");
        exit(1);
    }
    //Writing the array elements into file
    for(i=0; i<5; i++){
        if ( fwrite(&num[i], sizeof(int), 1, fp) != 1 ){
            printf("Error writing %d into file!\n", num[i]);
            exit(1);
        }
    }
    //Closing write stream
    if ( fclose(fp) == EOF ){
        printf("Error closing file!\n");
        exit(1);
    }
    //Clearing the array
    for(i=0; i<5; i++)  num[i]=-1;
    //Opening stream for reading from file
    //Error Checking fopen()
    if ( (fp=fopen("FILE.txt", "rb")) == NULL ){
        printf("Error Opening file for reading!\n");
        exit(1);
    }
    //Reading from file
    for(i=0; i<5; i++){
        if ( fread(&num[i], sizeof(int), 1, fp) != 1 ){
            printf("Error Reading!\n");
            exit(1);
        }
    }
    //Closing stream
    if ( fclose(fp) == EOF ){
        printf("Error closing file!\n");
        exit(1);
    }
    //Printing array
    for(i=0; i<5; i++){
        printf("%d\n", num[i]);
    }
    return 0;
}
