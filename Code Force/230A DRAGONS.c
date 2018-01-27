    #include <stdio.h>

    #define N 10000

    int x[N], y[N], temp[N], temp2[N];

    void merge(int lo, int hi){
        if (hi==lo)     return;
        int mid=(hi+lo)/2;
        merge(lo, mid);
        merge(mid+1, hi);
        int i,j,k;
        i=j=k=0;
        for (i=k=lo, j=mid+1; k<=hi; k++){
            if (i==mid+1){
                temp[k]=x[j];
                temp2[k]=y[j++];
            }
            else if (j==hi+1){
                temp[k]=x[i];
                temp2[k]=y[i++];
            }
            else if (x[i]<x[j]){
                temp[k]=x[i];
                temp2[k]=y[i++];
            }
            else{
                temp[k]=x[j];
                temp2[k]=y[j++];
            }
        }
        for (k=lo; k<=hi; k++){
            x[k]=temp[k];
            y[k]=temp2[k];
        }
    }
    int main(){
        int s=0,n=0,i=0,flag=1;
        scanf("%d %d", &s, &n);
        for (i=0; i<n; i++)
            scanf("%d %d", &x[i], &y[i]);

        merge(0, n-1);
        for (i=0; i<n; i++){
            if (s>x[i])
                s+=y[i];
            else{
                flag=0;
                break;
            }
        }
        if (flag)
            printf("YES\n");
        else
            printf("NO\n");
        return 0;
    }
