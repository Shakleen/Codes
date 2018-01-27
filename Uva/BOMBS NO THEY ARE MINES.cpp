//UVA 10653 Bombs! No they are mines
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

int fr[4] = {1, -1, 0, 0};
int fc[4] = {0, 0, 1, -1};

int main(){
    int r = 0, c = 0;

    while ( scan2(r,c) ){
        if (!r && !c){
            return 0;
        }

        int vis [r+1] [c+1] = {};

        int bomb_rows = 0, bomb_col = 0;

        scanf("%d", &bomb_rows);

        for (int i=0; i < bomb_rows; i++){
            int row = 0, bombs = 0;

            scan2(row, bombs);

            for(int j=0; j < bombs; j++){
                int  col = 0;

                scanf("%d", &col);

                vis [row] [col] = 2;//2 means bomb
            }
        }

        int row_start, row_end, col_start, col_end, dis [r+1] [c+1] = {};
        row_start = row_end = col_start = col_end = 0;

        scanf("%d %d %d %d", &row_start, &col_start, &row_end, &col_end);

        if (row_start == row_end && col_start == col_end){
            printf("0\n");
            continue;
        }

        vis [row_start] [col_start] = 1;
        dis [row_start] [col_start] = 0;

        queue <pii> q;

        q.push( pii (row_start, col_start) );

        while ( !q.empty() ){
            bool f = 0;
            pii cell = q.front();
            q.pop();

            for(int k=0; k < 4; k++){
                int kr = cell.first + fr [k], kc = cell.second + fc [k];

                if (vis [kr] [kc] == 2){
                    continue;
                }

                else if (kr>=0 && kr<r && kc>=0 && kc<c && !vis [kr] [kc]){
                    vis [kr] [kc] = 1;//1 for visited

                    dis [kr] [kc] = dis [cell.first] [cell.second] + 1;

                    q.push( pii (kr,kc) );
                }

                if (kr == row_end && kc == col_end){
                    f = 1;
                    break;
                }
            }

            if (f){
                break;
            }
        }

        printf("%d\n", dis [row_end] [col_end]);
    }
}
