//SPOJ 21326 Akbarr- akbar the great

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
    int t = 0;

    scanf("%d", &t);

    while (t--){
        int n = 0, //number of cities(nodes)
            r = 0, //number of roads(edges)
            m = 0; //number of soldiers

        scanf("%d %d %d", &n, &r, &m);

        vector <int> city [n+2];//storing connections
        vector <int> pro [n+2];//storing protectors
        map <int, int> index;
        int nodeno=1;
        bool flag = false;

        for (int i=0; i<n+2; i++){
            city[i].clear();
            pro[i].clear();
        }

        //establishing the connections
        for (int i = 0; i < r; i++){
            int a = 0, b = 0;

            scan2(a,b);

            if ( !index[a] )    index[a] = nodeno++;
            if ( !index[b] )    index[b] = nodeno++;

            city[ index[a] ].push_back( index[b] );
            city[ index[b] ].push_back( index[a] );
        }

        //establishing soldiers in the cities
        for (int i = 0; i < m; i++){
            int k = 0,//city no soldier put in
                s = 0;//strength of soldier

            scan2(k,s);

            if (flag){
                continue;
            }

            pro[ index[k] ].push_back( index[k] );

            queue <int> q;

            while ( !q.empty() ){
                q.pop();
            }

            q.push( index[k] );

            while ( !q.empty() && (s--) ){
                int pop = q.front(), //pop = index [k]
                    lim = city[pop].size();//no of neighbour cities

                q.pop();

                for (int i = 0; i < lim; i++){
                    int x = city [pop] [i],//x is neighbour city
                        p = pro[x].size();
                    if (x != index[k] && !p){
                        pro[x].push_back(k);
                        q.push(x);
                    }
                    else if (pro[x][0] != index[k]){
                        flag =  true;
                    }
                }
            }
        }

        for (int i=1; i<=n; i++){
            if (pro[i].size() != 1){
                flag = true;
//                printf("i=%d pro[i]=%d flag=%d\n",i, pro[i].size(),flag);
                break;
            }
        }

        if (flag){
            printf("No\n");
        }
        else{
            printf("Yes\n");
        }
    }

    return 0;
}
