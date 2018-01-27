#include <bits/stdc++.h>

void f (int a, char *ch);
bool cmp (int a, int b);

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int ad,bd,cd,dd,ab,bb,cb,db,i;
        ad=bd=cd=dd=ab=bb=cb=db=0;
        bool flag = true;

        scanf("%d.%d.%d.%d",&ad, &bd, &cd, &dd);
        scanf("%d.%d.%d.%d",&ab, &bb, &cb, &db);

        for (i = 1; i < 5; i++){
            char num [9] = {};
            int no  = 0;

            if (i == 1){
                f (ad, num);
                no = atoi (num);

                if ( cmp (no, ab) ){
                    flag = false;
                }
            }
            else if (i == 2){
                f (bd, num);
                no = atoi (num);

                if ( cmp (no, bb) ){
                    flag = false;
                }
            }
            else if (i == 3){
                f (cd, num);
                no = atoi (num);

                if ( cmp (no, cb) ){
                    flag = false;
                }
            }
            else{
                f (dd, num);
                no = atoi (num);

                if ( cmp (no, db) ){
                    flag = false;
                }
            }
        }

        if (flag)   printf("Case %d: Yes\n", cs);
        else        printf("Case %d: No\n", cs);
    }

    return 0;
}

void f (int a, char *ch){
    int i = 0, n = 0;
    for (i = 0; a!=0 ; i++, a /= 2){
        ch[i] = (a%2 + '0');
    }
    ch[i] = '\0';

    n = i;

    for (i = n - 1; i >= n/2; i--){
        char temp = ch[i];
        ch[i] = ch[n-1-i];
        ch[n-1-i] = temp;
    }

    return;
}

bool cmp (int a, int b){
    if (a != b) return 1;
    return 0;
}
