/*
MERGE SORTING
FASTEST WAY TO SORT ANY ARRAY
*/

#include <stdio.h>
//DECLARING ARRAYS TO WORK WITH
int num[1000], temp[1000];
void mergesort(int lo, int hi){
//If the sub-array only contains one element then it'll return
    if (lo==hi)
        return;
//Finding mid point to divide an array into 2 sub-arrays
    int mid=(lo+hi)/2;
//Recursion for the two sub-arrays
    mergesort(lo, mid);
    mergesort(mid+1, hi);
    int i,j,k;
    for (i=k=lo, j=mid+1; k<=hi; k++){
//If the first sub-array is done being sorted
        if (i==mid+1)
            temp[k]=num[j++];
//If the second sub-array is done being sorted
        else if (j==hi+1)
            temp[k]=num[i++];
//If the 1st element of 1st sub-array > the 1st element of 2nd sub-array
        else if (num[i]<num[j])
            temp[k]=num[i++];
//Vise-versa
        else
            temp[k]=num[j++];
    }
//Rewriting num array with the sorted sub-arrays
    for(k=lo; k<=hi; k++)
        num[k]=temp[k];
}

int main(){
    int i,size;
    i=size=0;
    printf("Please enter your array size:\n");
    scanf("%d", &size);
    printf("Enter array elements:\n");
    for (i=0; i<size; i++)
        scanf("%d", &num[i]);
//Sending the first and last index to merge function to sort
    mergesort(0,size-1);
    for (i=0; i<size; i++)
        printf("%5d", num[i]);
    return 0;
}
