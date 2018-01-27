#include <bits/stdc++.h>

using namespace std;

int main(){
    int t = 0;

    cin >> t;

    for (int cs = 1; cs <= t; cs++){
        cout << "Case " << cs << ":" << endl;

        string command, cur = "http://www.lightoj.com/";

        stack <string> goback, gofront;

        for (int i = 1; i < 101; i++){
            cin >> command;

            if (command == "VISIT"){
                goback.push(cur);

                cin >> cur;

                cout << cur << endl;

                while ( !gofront.empty() )  gofront.pop();
            }
            else if ( command == "BACK" ){
                if ( goback.empty() ){
                    cout << "Ignored" << endl;
                }
                else{
                    gofront.push(cur);
                    cur = goback.top();
                    goback.pop();

                    cout << cur << endl;
                }
            }
            else if ( command == "FORWARD" ){
                if ( gofront.empty() ){
                    cout << "Ignored" << endl;
                }
                else{
                    goback.push(cur);
                    cur = gofront.top();
                    gofront.pop();

                    cout << cur << endl;
                }
            }
            else if ( command == "QUIT" ){
                break;
            }
        }
    }

    return 0;
}
