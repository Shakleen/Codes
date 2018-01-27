//UVa Shipping Routes
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
    int data_sets = 0;

    scanf("%d", &data_sets);

    printf("SHIPPING ROUTES OUTPUT\n\n");

    for (int i = 1; i <= data_sets; i++){
        int m = 0,//No of warehouses
            n = 0,//No of shipping legs
            p = 0,//no of shipping requests
            whouse = 1;//mapping number for warehouses

        scanf("%d %d %d", &m, &n, &p);

        //Mapping strings to integers

        map <string, int> mymap;

        for (int code_no = 1; code_no <= m; code_no++){
            char code [3] = {}; //

            scanf("%s", code);

            if (mymap.find( code ) == mymap.end()){
                mymap [ code ] = whouse++;
            }
        }

        //Connecting warehouses with shipping legs

        vector <int> legs [m+2];

        for (int leg_no = 1; leg_no <= n; leg_no++){
            char source [3] = {},//starting of shipping leg
                destination [3] = {};//ending of that shipping leg

            scanf("%s %s", source, destination);

            int w1 = mymap[source], w2 = mymap[destination];

            legs[w1].push_back(w2);
            legs[w2].push_back(w1);
        }

        //processing shipping requests and costs

        printf("DATA SET  %d\n\n", i);

        for (int query = 1; query <= p; query++){

            int shipment_size = 0,//size of shipment
                dist[n+2] = {};

            bool vis [m+2] = {}, flag = false;

            char source [3] = {},//starting of shipment
                 destination [3] = {};//ending of that shipment

            scanf("%d %s %s", &shipment_size, source, destination);

            int s = mymap [source], d = mymap [destination];

            if (!legs[s].size() || !legs[d].size()){

                printf("NO SHIPMENT POSSIBLE\n");

                continue;
            }

            vis [s] = true;
            dist [s] = 0;

            queue <int> q;
            q.push( s );

            while ( !q.empty() ){
                int pop = q.front(), no = legs [pop].size();
                q.pop();

                for (int j = 0; j < no; j++){
                    int x = legs [pop] [j];

                    if ( !vis[x] ){
                        vis[x] = true;
                        dist [x] = dist[pop] + 1;

                        if (x == d){
                            flag = true;//destination reached
                            break;
                        }
                        q.push(x);
                    }
                }

                if (flag){//breaking condition true
                    break;
                }
            }

            if (vis[d]){
                int cost = dist [d] * shipment_size * 100;
                printf("$%d\n", cost);
            }
            else{
                printf("NO SHIPMENT POSSIBLE\n");
            }
        }
        printf("\n");
    }

    printf("END OF OUTPUT\n");
    return 0;
}
