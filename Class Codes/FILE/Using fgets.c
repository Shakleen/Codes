#include <stdio.h>

int main(){
    FILE *fp;
    if( (fp=fopen("FILE.txt", "r")) == NULL){
        printf("Error in creating!\n");
        exit(1);
    }
    char ch[100]={};
    while(1){
        if( fgets(ch,100,fp) == NULL ){
            printf("\nEnd of file!\n");
            break;
        }
        else{
            printf("%s\n",ch);
        }
    }
    return 0;
}
