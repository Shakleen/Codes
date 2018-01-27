#include <bits/stdc++.h>

using namespace std;

bool compare (pair<int,pair<int,int> > a, pair<int,pair<int,int> > b){
    if (a.first == b.first){
        if (a.second.first == b.second.first){
            return (a.second.second < b.second.second);
        }

        return (a.second.first < b.second.first);
    }

    return (a.first < b.first);
}

int main(){
    int t = 0;

    scanf("%d", &t);

    while ( t-- ){
        int n = 0, D = 0, trainer = 0;
        long long ans = 0;
        vector < pair < int, pair < int , int > > > v;
        priority_queue <int> q;

        scanf("%d %d", &n, &D);

        bool cls [D+1] = {}, flag = false;

        for (int i = 0; i < n; i++){
            //x => day  y => lectures  z => sadness lvl
            int x = 0, y = 0, z = 0;

            scanf("%d %d %d", &x, &y, &z);

            v.push_back(make_pair(x, make_pair(z,y)));
        }

        sort(v.begin(), v.end(), compare);

        for (int i = 0; i < n; i++){
//First input
            if ( !i ){
//Pushing sadness lvl in queue
                q.push(v[i].second.first);
//1st trainer assign
                trainer = i;
//1st lecture given by 1st trainer
                v[trainer].second.second--;
                cls [v[trainer].first] = true;

//Trainer finished giving lectures
                if (!v[trainer].second.second){
//So take it out of the queue
                    q.pop();
                }
            }
//For the rest of the input
            else{
//same day arrival
                if (v[i].first == v[i-1].first && v[i].second.first > q.top()){
                    flag = true;
//New one is sadder
                    if (!v[ trainer ].second.second)        q.push(v[ trainer ].second.first);
//Old one won't give the lecture
                    v[ trainer ].second.second++;
//New 1 becomes current trainer
                    trainer = i;
                    //Lecture given
                    v[ trainer ].second.second--;

                    cls [v[trainer].first] = true;

                    if (!v[ trainer ].second.second){
                        q.pop();

                        int x = q.top();

                        for (int j = i; j >= 0; j--){
                            if (v[j].second.first == x && v[j].second.second){
                                trainer = j;
                                break;
                            }
                        }
                    }
                }
                else                    flag = false;


                if (v[i].second.first > q.top())            trainer = i;
//Pushing sadness lvl in queue
                q.push(v[i].second.first);

                int dif = 0, strt = v[i].first;

                if (v[ trainer ].second.second)     dif = v[i].first - v[i-1].first;
                else                                dif = 1;

                if (i == n-1)                       dif += (D-v[i].first);
                if (flag)                           strt++;

                if (!v[ trainer ].second.second)    trainer = i;

                while ( dif ){
                    dif--;

                    if (!cls[strt]){
                            v[ trainer ].second.second--;
                            cls [strt] = true;
                    }
                    strt++;

                    if (!v[ trainer ].second.second){
                        q.pop();

                        if (q.empty()){
                            break;
                        }

                        int x = q.top();

                        for (int j = i; j >= 0; j--){
                            if (v[j].second.first == x && v[j].second.second){
                                trainer = j;
                                break;
                            }
                        }
                    }

                }
            }
        }

        while (!q.empty()){
            int k = q.top();

            for (int j = 0; j < n; j++){
                if (v[j].second.first == k && v[j].second.second){
                    trainer = j;
                    break;
                }
            }

            ans += k*v[trainer].second.second;

            q.pop();
        }
        printf("%lld\n", ans);
    }


    return 0;
}
