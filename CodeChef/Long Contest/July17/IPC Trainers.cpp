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

        for (int i = 0; i < 3; i++){
            printf("Arrival = %d Trainer = %d Lecture = %d sadness = %d\n",
                   v[i].first ,i, v[i].second.first, v[i].second.second);
        }
        for (int i = 0; i < n; i++){
printf("\ni = %d\n\n", i);
//First input
            if ( !i ){
//Pushing sadness lvl in queue
                q.push(v[i].second.first);
printf("Pushed into queue %d\n", v[i].second.first);
//1st trainer assign
                trainer = i;
printf("1Current trainer = %d lectures=%d sadness = %d\n", trainer, v[trainer].second.second, v[trainer].second.first);
//1st lecture given by 1st trainer
                v[trainer].second.second--;
printf("%d day taken by trainer %d\n", v[trainer].first, trainer);
                cls [v[trainer].first] = true;

printf("After t=%d\n", v[trainer].second.second);
//Trainer finished giving lectures
                if (!v[trainer].second.second){
printf("Popping %d\n", q.top());
//So take it out of the queue
                    q.pop();
                }
            }
//For the rest of the input
            else{
//same day arrival
                if (v[i].first == v[i-1].first && v[i].second.first > q.top()){
                        flag = true;
printf("Arrival on the same day!\n");
//New one is sadder
printf("Next one is sadder!\n");
                    if (!v[ trainer ].second.second){
printf("Pusing into queue %d\n", v[ trainer ].second.first);
                        q.push(v[ trainer ].second.first);
                    }
//Old one won't give the lecture
                    v[ trainer ].second.second++;
printf("Old one won't give lecture! trainer = %d lectures = %d\n",trainer,v[ trainer ].second.second);
//New 1 becomes current trainer
                    trainer = i;
printf("2Current trainer = %d lectures=%d sadness = %d\n", trainer, v[trainer].second.second, v[trainer].second.first);
                    //Lecture given
                    v[ trainer ].second.second--;
printf("trainer = %d lectures = %d\n", trainer, v[ trainer ].second.second);
printf("%d day taken by trainer %d\n", v[trainer].first, trainer);
                    cls [v[trainer].first] = true;
                    if (!v[ trainer ].second.second){
printf("Lectures finished!\n");
printf("Popping %d\n", q.top());
                        q.pop();

                        int x = q.top();
printf("q.top() = %d\n", x);
                        for (int j = i; j >= 0; j--){
                            if (v[j].second.first == x && v[j].second.second){
                                trainer = j;
                                break;
                            }
                        }
printf("4Current trainer = %d lectures=%d sadness = %d\n", trainer, v[trainer].second.second, v[trainer].second.first);
                    }
                }
                else{
                    flag = false;
                }

                if (v[i].second.first > q.top()){
                    trainer = i;
printf("4.5Current trainer = %d lectures=%d sadness = %d\n", trainer, v[trainer].second.second, v[trainer].second.first);
                }
//Pushing sadness lvl in queue
                q.push(v[i].second.first);
printf("Pushed into queue %d\n", v[i].second.first);

                int dif = 0, strt = v[i].first;

                if (v[ trainer ].second.second){
                    dif = v[i].first - v[i-1].first;
                }
                else{
                    dif = 1;
                }
printf("Dif = %d\n", dif);
                if (i == n-1){
                    dif += (D-v[i].first);
                }
printf("dif = %d d[i] = %d d[i-1] = %d\n", dif, v[i].first, v[i-1].first);
                if (!v[ trainer ].second.second){
printf("5Current trainer = %d lectures=%d sadness = %d\n", trainer, v[trainer].second.second, v[trainer].second.first);
                    trainer = i;
                }
                while ( dif ){
                    dif--;
                    if (flag)   strt++;
printf("Status of class %d is %d\n", strt, cls[strt]);
                    if (!cls[strt]){
                            v[ trainer ].second.second--;
                            cls [strt] = true;
                    }
                    strt++;
printf("En trainer=%d dif=%d lec=%d\n", trainer,dif,v[ trainer ].second.second);
                    if (!v[ trainer ].second.second){
                        q.pop();
printf("Lectures done!\n");
                        if (q.empty()){
printf("No more lecturers!\n");
                            break;
                        }

                        int x = q.top();
printf("q.top() = %d\n", x);
                        for (int j = i; j >= 0; j--){
                            if (v[j].second.first == x && v[j].second.second){
                                trainer = j;
                                break;
                            }
                        }
printf("6Current trainer = %d lectures=%d sadness = %d\n", trainer, v[trainer].second.second, v[trainer].second.first);
                    }

printf("Ex trainer=%d dif=%d lec=%d\n", trainer,dif,v[ trainer ].second.second);
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
printf("ans = %lld k = %d lec = %d\n", ans, k, v[trainer].second.second);
            q.pop();
        }
        printf("%lld\n", ans);
    }


    return 0;
}
