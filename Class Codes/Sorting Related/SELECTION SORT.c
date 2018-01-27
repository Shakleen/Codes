/*
SELECTION SORT ALGORITHM
*/
#include <stdio.h>
//Defining the highest size for array
#define N 100
int main(){
    int m[N]={};
    int i, j, size, minindex=0;
    i=j=size=0;
    //Taking row size input from user
    printf("Enter array Size:\n");
    scanf("%d", &size);
    //Inputting array
    printf("Input array elements:\n");
    for (i=0; i<size; i++)
        scanf("%d", &m[i]);
    printf("Inputted array:\n");
    for (i=0; i<size; i++)
        printf("%5d", m[i]);
    //No of Passes = array size - 1
    int pass=size-1;
    //Outer loop controls no of passes
    for (i=0; i<pass; i++){
        minindex=i;
        //Inner loop controls the indexes for comparison
        //j=i+1 because the first comparison will be
        //between i and i+1 for each pass
        for (j=i+1; j<size; j++){
        //Comparing the elements
        //The index of the smallest value will be saved to minindex by comparing
            if (m[minindex]>m[j])
                minindex=j;
        }
        if (i!=minindex){
            int temp=m[i];
            m[i]=m[minindex];
            m[minindex]=temp;
        }
    }
    printf("\nSorted Array:\n");
    for (i=0; i<size; i++)
        printf("%5d", m[i]);

    return 0;
}
