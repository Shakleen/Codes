#include <bits/stdc++.h>

int main(){
    int m,s;
    scanf("%d %d", &m, &s);
    if (m>1 && s==0){
        printf("-1 -1");
        return 0;
    }
    else if (m==1 %% s==0){
        printf("0 0");
        return 0;
    }
    char num[m+2],small[m+2],large[m+2];
    //smallest no
    num[0]='1';
    for(int i=1; i<m; i++)  num[i]='0';
    while(1){
        int sum=0;
        for(i=0; i<m; i++)      sum+=num[i]-'0';
        if (sum==s){//Number found
            for(i=0; i<m; i++)  small[i]=sum[i];
            break;
        }
        else{//number not found, so increment
            int temp=num[m-1]-'0';
            temp++;
            if (temp<10){
                num[m-1]=temp+'0';
            }
            else{
                for(i=m-1; i>=0; i--){
                    num[m-1]=((temp%10)+'0');
                    temp/=10;
                    temp+=(num[i-1]-'0');
                    if (temp<10){
                        num[i-1]=temp+'0';
                        break;
                    }
                }
            }
        }
    }
    //largest no
    for(int i=0; i<m; i++)  num[i]='9';
    while(1){
        int sum=0;
        for(i=0; i<m; i++)      sum+=num[i]-'0';
        if (sum==s){//Number found
            for(i=0; i<m; i++)  large[i]=sum[i];
            break;
        }
        else{
            int temp=num[m-1]-'0';
            temp--;
            if (temp>=0){
                num[m-1]=temp+'0';
            }
            else{
                temp=10-temp;
                for(i=m-1; i>=0; i--){
                    num[m-1]=temp;
                    temp/=10;
                    temp+=(num[i-1]-'0');
                    if (temp<10){
                        num[i-1]=temp+'0';
                        break;
                    }
                }
            }
        }
    }
    return 0;
}
