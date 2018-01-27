//UVA 10004 Bicolouring
#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)
#define pii                 pair <int, int>

int main(){
    int n = 0;

    while ( scanf("%d", &n) ){
        if (!n){
            break;
        }

        int l = 0, start = 0;

        scanf("%d", &l);

        bool grid [l+1] [l+1], f = false, flag = true;

        for (int i=0; i<=l; i++){
            memset (grid[i], false, sizeof(grid[i]));
        }

        for(int i = 0; i < l; i++){
            int a1 = 0, a2 = 0;

            scan2(a1,a2);

            if (!f){
                start = a1;
            }

            grid [a1] [a2] = grid [a2] [a1] = 1;
        }

        int colour [l+1] = {}; //zero means not coloured

        colour [start] = 1; //one means red

        queue <int> q;

        q.push(start);

        while ( !q.empty() ){
             int pop = q.front();
             q.pop();

             for (int i = 0; i < l; i++){
                if ( grid [pop] [i] ){
                    if ( !colour[i] ){//i is not coloured

                        if (colour [pop] == 1)//pop is coloured red
                            colour [i] = 2;
                        else//pop is coloured blue
                            colour [i] = 1;

                        q.push(i);
                    }

                    //i is coloured
                    if ( colour[i] == colour [pop] ){
                        flag = false;
                        break;
                    }
                }
             }

             if (!flag){
                break;
             }
        }

        if (flag){
            printf("BICOLORABLE.\n");
        }
        else{
            printf("NOT BICOLORABLE.\n");
        }
    }

    return 0;
}
