#include <bits/stdc++.h>
using namespace std;
int main(){
    char s=0, str[102]={};
    scanf("%c %s", &s, &str);
    int i=0;
    while(str[i]){
        switch(str[i]){
        case 'a':
            if (s=='L') str[i]='s';
            i++;
            break;
        case 'b':
            if (s=='L') str[i]='n';
            else        str[i]='v';
            i++;
            break;
        case 'c':
            if (s=='L') str[i]='v';
            else        str[i]='x';
            i++;
            break;
        case 'd':
            if (s=='L') str[i]='f';
            else        str[i]='s';
            i++;
            break;
        case 'e':
            if (s=='L') str[i]='r';
            else        str[i]='w';
            i++;
            break;
        case 'f':
            if (s=='L') str[i]='g';
            else        str[i]='d';
            i++;
            break;
        case 'g':
            if (s=='L') str[i]='h';
            else        str[i]='f';
            i++;
            break;
        case 'h':
            if (s=='L') str[i]='j';
            else        str[i]='g';
            i++;
            break;
        case 'i':
            if (s=='L') str[i]='o';
            else        str[i]='u';
            i++;
            break;
        case 'j':
            if (s=='L') str[i]='k';
            else        str[i]='h';
            i++;
            break;
        case 'k':
            if (s=='L') str[i]='l';
            else        str[i]='j';
            i++;
            break;
        case 'l':
            if (s=='L') str[i]=';';
            else        str[i]='k';
            i++;
            break;
        case 'm':
            if (s=='L') str[i]=',';
            else        str[i]='n';
            i++;
            break;
        case 'n':
            if (s=='L') str[i]='m';
            else        str[i]='b';
            i++;
            break;
        case 'o':
            if (s=='L') str[i]='p';
            else        str[i]='i';
            i++;
            break;
        case 'p':
            if (s=='R') str[i]='o';
            i++;
            break;
        case 'q':
            if (s=='L') str[i]='w';
            i++;
            break;
        case 'r':
            if (s=='L') str[i]='t';
            else        str[i]='e';
            i++;
            break;
        case 's':
            if (s=='L') str[i]='d';
            else        str[i]='a';
            i++;
            break;
        case 't':
            if (s=='L') str[i]='y';
            else        str[i]='r';
            i++;
            break;
        case 'u':
            if (s=='L') str[i]='i';
            else        str[i]='y';
            i++;
            break;
        case 'v':
            if (s=='L') str[i]='b';
            else        str[i]='c';
            i++;
            break;
        case 'w':
            if (s=='L') str[i]='e';
            else        str[i]='q';
            i++;
            break;
        case 'x':
            if (s=='L') str[i]='c';
            else        str[i]='z';
            i++;
            break;
        case 'y':
            if (s=='L') str[i]='u';
            else        str[i]='t';
            i++;
            break;
        case 'z':
            if (s=='L') str[i]='x';
            i++;
            break;
        case ',':
            if (s=='L') str[i]='.';
            else        str[i]='m';
            i++;
            break;
        case '.':
            if (s=='L') str[i]='/';
            else        str[i]=',';
            i++;
            break;
        case '/':
            if (s=='R') str[i]='.';
            i++;
            break;
         case ';':
            if (s=='R') str[i]='l';
            i++;
            break;
        }
    }
    printf("%s", str);
    return 0;
}
