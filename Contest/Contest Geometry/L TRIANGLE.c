#include <stdio.h>

int num[4], temp[4];

void mergesort(int lo, int hi){
    if (lo==hi)
        return;
    int mid=(lo+hi)/2;
    mergesort(lo, mid);
    mergesort(mid+1, hi);
    int i,j,k;  i=j=k=0;
    for (i=k=lo, j=mid+1; k<=hi; k++){
        if (i==mid+1)
            temp[k]=num[j++];
        else if (j==hi+1)
            temp[k]=num[i++];
        else if (num[i]<num[j])
            temp[k]=num[i++];
        else
            temp[k]=num[j++];
    }
    for(k=lo; k<=hi; k++)
        num[k]=temp[k];
}


int main(){
    int i=0, max=0;
    for (i=0; i<4; i++)
        scanf("%d", &num[i]);
    mergesort(0,3);
    if (num[0]+num[1]>num[3]||num[0]+num[2]>num[3]||num[1]+num[2]>num[3])
        printf("TRIANGLE\n");
    else if (num[0]+num[1]>num[2])
        printf("TRIANGLE");
    else{
        if (num[0]+num[1]==num[3]||num[0]+num[2]==num[3]||num[1]+num[2]==num[3])
            printf("SEGMENT\n");
        else if (num[0]+num[1]==num[2])
            printf("SEGMENT\n");
        else
            printf("IMPOSSIBLE\n");
    }
    return 0;
}
