/*
BUBBLE SORT ALGORITHM
*/
#include <stdio.h>
//Defining the highest size for array
#define N 100
int main(){
    int m[N]={0};
    int i, j, size;
    i=j=size=0;
    //Taking row size input from user
    printf("Enter array Size:\n");
    scanf("%d", &size);
    //Inputting array
    printf("Input array elements:\n");
    for (i=0; i<size; i++)
        scanf("%d", &m[i]);
    //No of Passes = array size - 1
    int pass=size-1;
    //Outer loop controls no of passes
    for (i=0; i<pass; i++){
        //Inner loop controls the indexes for comparison
        for (j=0; j<pass-i; j++){
            //Comparing the elements in indexes j and j+1
            if (m[j]>m[j+1]){
                int t = m[j+1];
                m[j+1]=m[j];
                m[j]=t;
            }
        }
    }
    for (i=0; i<size; i++)
        printf("%5d", m[i]);

    return 0;
}
