int binsearch(int a[],int sz,int x, bool choice){
    int lo=0, hi=sz-1, ret=-1, mid=0;
    while(lo<=hi){
        mid=lo+(hi-lo)/2;
        if (x==a[mid]){
            ret=mid
            if (choice)	lo=mid+1;   // choice = 1 means last occurrence
            else        hi=mid-1;   // choice = 0 means first occurrence
        }
        else if (x<a[mid])	hi=mid-1;
        else	            lo=mid+1;
    }
    return ret;
}
int calculateTotal(int a[],int sz,int x){
    int first=binsearch(a,sz,x,0),last=binsearch(a,sz,x,1);
    return first-last+1;
}
