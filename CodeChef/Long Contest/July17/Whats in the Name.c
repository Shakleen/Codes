#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
    int t = 0;

    scanf("%d ", &t);

    while (t--){
        char f [11] = {}, m [11] = {}, l [11] = {}, name[40] = {};

        gets(name);

        int len = strlen(name), i = 0, j = 0, k = 0;

        for (i = 0; i < len; i++){
            if (name [i] == ' '){
                j = 0;
                k++;
                continue;
            }

            if ( !k ){
                f [j] = tolower(name [i]);

                if ( !j )   f [j] = toupper(f [j]);

                j++;
            }
            else if ( k == 1 ){
                m [j] = tolower(name [i]);

                if ( !j ) m [j] = toupper(m [j]);

                j++;
            }
            else if ( k == 2 ){
                l [j] = tolower(name [i]);

                if ( !j ) l [j] = toupper(l [j]);

                j++;
            }
        }

        int lenf = strlen(f), lenm = strlen(m), lenl = strlen(l);

        if ( lenf && lenm && lenl ){
            printf("%c. %c. %s\n", f[0], m[0], l);
        }
        else if ( lenf && lenm ){
            printf("%c. %s\n", f[0], m);
        }
        else{
            printf("%s\n", f);
        }
    }

    return 0;
}
