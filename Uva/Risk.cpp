//UVA 567 Risk

#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

bool mat[22][22];

void res(void){
    for (int i=0; i<21; i++){
        memset(mat[i], false, sizeof(mat[i]));
    }

    return;
}

int main(){
    int test=1;

    while(1){
        res();

        for (int i=1; i<20; i++){
            int no=0;

            if ( scanf("%d", &no) == EOF){
                return 0;
            }

            for (int j=0; j<no; j++){
                int neighbour=0;

                scanf("%d", &neighbour);

                mat [neighbour] [i] = mat [i] [neighbour] = true;
            }
        }

        int pair_c = 0;

        scanf("%d", &pair_c);

        printf("Test Set #%d\n", test);

        for(int i=0; i<pair_c; i++){
            int start=0, destination=0,cnt=0,dist[22];

            memset(dist, -1, sizeof(dist));

            scan2(start,destination);

            dist[start] = 0;

            queue <int> q;
            q.push(start);

            while ( !q.empty() ){
                int pop = q.front();
                q.pop();

                for (int i=1; i<21; i++){
                    if (dist[i] == -1 && mat [pop] [i]){
                        dist[i] = dist[pop] + 1;
                        q.push(i);
                    }
                }
            }
            printf("%2d to %2d: %d\n", start, destination, dist[destination]);
        }

        test++;

        printf("\n");
    }
    return 0;
}
