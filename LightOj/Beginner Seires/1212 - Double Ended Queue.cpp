#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    scanf("%d", &t);

    for (int cs = 1; cs <= t; cs++){
        int n = 0, m = 0, x = 0;

        scanf("%d %d", &n, &m);

        deque <int> q;

        printf("Case %d:\n", cs);

        for (int i = 0; i < m; i++){
            string command;

            cin >> command;

            if ( command == "pushLeft" ){
                scanf("%d", &x);

                if ( q.size() < n ){
                    q.push_back(x);

                    printf("Pushed in left: %d\n", x);
                }
                else{
                    printf("The queue is full\n");
                }
            }
            else if ( command == "pushRight" ){
                scanf("%d", &x);

                if ( q.size() < n ){
                    q.push_front(x);

                    printf("Pushed in right: %d\n", x);
                }
                else{
                    printf("The queue is full\n");
                }
            }
            else if ( command == "popLeft" ){
                if ( q.empty() ){
                    printf("The queue is empty\n");
                }
                else{
                    printf("Popped from left: %d\n", q.back());

                    q.pop_back();
                }
            }
            else if ( command == "popRight" ){
                if ( q.empty() ){
                    printf("The queue is empty\n");
                }
                else{
                    printf("Popped from right: %d\n", q.front());

                    q.pop_front();
                }
            }
        }
    }

    return 0;
}
