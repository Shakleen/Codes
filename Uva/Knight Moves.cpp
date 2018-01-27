//UVA 439 Knight Moves
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
#define ROW                 8
#define COL                 8

bool vis[10][10];
int fr[8] = {2, 2, -2, -2, 1, 1, -1, -1};
int fc[8] = {1, -1, 1, -1, 2, -2, 2, -2};

int col_mapping (char ch);
void res (void);

int main(){
    int row_start, row_end;
    char col1, col2;

    row_start = row_end = col1 = col2 = 0;

    while ( scanf(" %c%d %c%d",&col1, &row_start, &col2, &row_end) != EOF){

        if (row_start == row_end && col1 == col2){
            printf("To get from %c%d to %c%d takes %d knight moves.\n",
               col1, row_start, col2, row_end, 0);

            continue;
        }

        int col_start = col_mapping (col1),
            col_end = col_mapping (col2),
            dist[10][10] = {}, move_no = 1;

        res();

        dist [row_start] [col_start] = 0;
        vis [row_start] [col_start] = true;

        queue <pii> q;
        q.push(pii(row_start, col_start));

        while ( !q.empty() ){
            pii top = q.front();
            q.pop();

            for (int k=0; k<8; k++){
                int r = top.first + fr[k],
                    c = top.second + fc[k];

                if (r>0 && r<=ROW && c>0 && c<=COL && !vis[r][c]){
                    vis [r] [c] = true;
                    dist [r] [c] = dist [top.first] [top.second] + 1;
                    q.push(pii(r,c));
                }
            }
        }

        printf("To get from %c%d to %c%d takes %d knight moves.\n",
               col1, row_start, col2, row_end, dist [row_end] [col_end]);
    }

    return 0;
}

int col_mapping (char ch){
    switch(ch){
        case 'a':
        return 1;
        break;

        case 'b':
        return 2;
        break;

        case 'c':
        return 3;
        break;

        case 'd':
        return 4;
        break;

        case 'e':
        return 5;
        break;

        case 'f':
        return 6;
        break;

        case 'g':
        return 7;
        break;

        case 'h':
        return 8;
        break;
    }
}

void res (void){
    for(int i=0; i<10; i++){
        memset (vis [i], false, sizeof( vis [i] ));
    }

    return;
}
