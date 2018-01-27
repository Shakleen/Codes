//UVA 336 A NODE IS TOO FAR

#include <bits/stdc++.h>

using namespace std;

#define ll                  long long
#define min3(a,b,c)         min(a,min(b,c))
#define max3(a,b,c)         max(a,max(b,c))
#define min4(a,b,c,d)       min(a,min(b,min(c,d)))
#define max4(a,b,c,d)       max(a,max(b,max(c,d)))
#define sqr(a)              ((a)*(a))
#define scan2(a,b)          scanf("%d %d", &a, &b)

bool mat[33][33];

void res(void){
    for (int i=0; i<33; i++){
        memset(mat[i], false, sizeof(mat[i]));
    }
    return;
}

int main(){
    int nc=0, cs=1;

    while(1){

        scanf("%d", &nc);

        if (nc == 0){
            break;
        }

        res();

        map <int, int> index;
        int nodenumber=1;

        for(int i=1; i<=nc; i++){
            int x=0, y=0;

            scan2(x,y);

            if ( !index[x] )    index[x] = nodenumber++;
            if ( !index[y] )    index[y] = nodenumber++;

            mat[index[x]][index[y]] = mat[index[y]][index[x]] = true;
        }

        int dist[33]={}, query=0, ttl=0;

        while ( 1 ){
            scan2(query,ttl);

            if (!query && !ttl){
                break;
            }

            memset(dist, -1, sizeof(dist));

            dist[index[query]] = 0;

            queue <int> q;
            q.push(index[query]);

            while ( !q.empty() ){
                int pop = q.front();
                q.pop();

                for (int i=1; i<nodenumber; i++){
                    if (dist[i] == -1 && mat[pop][i]){
                        dist[i] = dist[pop] + 1;
                        q.push(i);
                    }
                }
            }

            int cnt = 0;

            for (int i=1; i<nodenumber; i++){
                if (dist[i] == -1 || dist[i] > ttl){
                    cnt++;
                }
            }

            printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",
                   cs,cnt,query,ttl);
            cs++;
        }
    }
    return 0;
}
