#include <bits/stdc++.h>

using namespace std;

int main(){
    string f, s, str;

    cin >> f >> s >> str;

    int len = str.size();

    char str2[len];

    map <char, char> mymap;

    for (int i = 0; i < 26; i++){
        if ( !mymap[f[i]] ){
            mymap[f[i]] = s[i];
        }
    }

    for (int i = 0; i < len; i++){
        if ((str[i] > 64 && str[i] < 91) || (str[i] > 96 && str[i] < 123)){
            char ch = tolower(str[i]);
            str2[i] = mymap[ch];

            if (str[i] < 91){
                str2[i] = toupper(str2[i]);
            }
        }
        else{
            str2[i] = str[i];
        }
    }

    str2[len] = '\0';

    cout << str2 << endl;

    return 0;
}
