#include <bits/stdc++.h>

using namespace std;

int main(){
    int r [16] = {}, g [16] = {}, b [16] = {};

    {
    r[0] = g [0] = b [0] = 255;
    r[1] = g [1] = b [1] = 192;
    r[2] = g [2] = b [2] = 128;
    r[3] = g [3] = b [3] = 0;
    r[4] = 255;    g [4] = b [4] = 0;
    r[5] = 128;    g [5] = b [5] = 0;
    r[6] = g [6] = 255;    b[6] = 0;
    r[7] = g [7] = 128;    b[7] = 0;
    g[8] = 255;     r[8] = b [8] = 0;
    g[9] = 128;     r[9] = b [9] = 0;
    b[10] = g [10] = 255;    r[10] = 0;
    b[11] = g [11] = 128;    r[11] = 0;
    b[12] = 255;     r[12] = g [12] = 0;
    b[13] = 128;     r[13] = g [13] = 0;
    r[14] = b [14] = 255;    g [14] = 0;
    r[15] = b [15] = 128;    g [15] = 0;
    }

    while (1){
        int red = 0, green = 0, blue = 0, mn = INT_MAX, index = 0;

        scanf("%d %d %d", &red, &green, &blue);

        if (red == -1 && green == -1 && blue == -1){
            break;
        }

        for (int i = 0; i < 16; i++){
            int d = (r[i] - red)*(r[i] - red) + (g[i]-green)*(g[i]-green) + (b[i]-blue)*(b[i]-blue);

            if (d < mn){
                index = i;
                mn = d;
            }
        }

        switch (index){
        case 0:
            printf("White\n");
            break;
        case 1:
            printf("Silver\n");
            break;
        case 2:
            printf("Gray\n");
            break;
        case 3:
            printf("Black\n");
            break;
        case 4:
            printf("Red\n");
            break;
        case 5:
            printf("Maroon\n");
            break;
        case 6:
            printf("Yellow\n");
            break;
        case 7:
            printf("Olive\n");
            break;
        case 8:
            printf("Lime\n");
            break;
        case 9:
            printf("Green\n");
            break;
        case 10:
            printf("Aqua\n");
            break;
        case 11:
            printf("Teal\n");
            break;
        case 12:
            printf("Blue\n");
            break;
        case 13:
            printf("Navy\n");
            break;
        case 14:
            printf("Fuchsia\n");
            break;
        case 15:
            printf("Purple\n");
            break;
        }
    }

    return 0;
}
