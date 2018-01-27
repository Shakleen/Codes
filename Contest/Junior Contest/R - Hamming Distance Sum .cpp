#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define N 200001

int a[N], b[N];

int main(){
    scanf("%s %s", a, b);

//    int len1 = strlen(a), len2 = strlen(b), cnt=0;

//    if (len1 == len2){
//        for (int i=0; i<len1; i++){
//            int na=a[i]-'0', nb=b[i]-'0';
//
//            cnt += (na^nb);
//        }
    int cnt =0;
    cnt = (a^b);
//    }
//    else{
//        int no1 = 0, no2 = 0, flag = 0, j = len1-1;
//        bool ans[len2]={};
//
//        for (int i=0; i<len2; i++){
//            if (i==j){
//                if
//            }
//        }
//    }

    printf("%d", cnt);
    return 0;
}
