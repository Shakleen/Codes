#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int compare (const void *a, const void * b)
{  return ( *(char *)a - *(char *)b ); }
void swap (char* a, char* b){//A utility function two swap two characters a and b
    char t = *a;
    *a = *b;
    *b = t;
}
// This function finds the index of the smallest character which is greater than 'first' and is present in str[l..h]
int findCeil (char str[], char first, int l, int h){
    int ceilIndex = l;// initialize index of ceiling element
    for (int i = l+1; i <= h; i++)//Now iterate through rest of the elements and find the smallest character greater than 'first'
      if (str[i] > first && str[i] < str[ceilIndex])
            ceilIndex = i;
    return ceilIndex;
}
void sortedPermutations ( char str[] ){// Print all permutations of str in sorted order
    int size = strlen(str);// Get size of string
    qsort( str, size, sizeof( str[0] ), compare );    // Sort the string in increasing order
    bool isFinished = false;// Print permutations one by one
    while ( ! isFinished ){// print this permutation
        printf ("%s \n", str);
        int i;// Find the rightmost character which is smaller than its next character. Let us call it 'first char'
        for ( i = size - 2; i >= 0; --i )
           if (str[i] < str[i+1])
              break;
// If there is no such chracter, all are sorted in decreasing order, means we just printed the last permutation and we are done.
        if ( i == -1 )
            isFinished = true;
        else{//Find the ceil of 'first char' in right of first character. Ceil of a character is the smallest character greater than it
            int ceilIndex = findCeil( str, str[i], i + 1, size - 1 );
            swap( &str[i], &str[ceilIndex] );// Swap first and second characters
            qsort( str + i + 1, size - i - 1, sizeof(str[0]), compare );// Sort the string on right of 'first char'
        }
    }
}
int main(){// Driver program to test above function
    char str[] = "ABCD";
    sortedPermutations( str );
    return 0;
}
