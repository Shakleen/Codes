#include<bits/stdc++.h>
using namespace std;
int getMaxArea(int hist[], int n){
// Create an empty stack. The stack holds indexes of hist[] array The bars stored in
// stack are always in increasing order of their heights.
    stack<int> s;
    int max_area = 0, // Initalize max area
        i = 0;
    while (i < n){// Run through all bars of given histogram
// If this bar is higher than the bar on top stack, push it to stack
        if (s.empty() || hist[s.top()] <= hist[i])  s.push(i++);
// If this bar is lower than top of stack, then calculate area of rectangle with stack top
// as the smallest (or minimum height) bar. 'i' is 'right index' for the top and element
// before top in stack is 'left index'
        else{// Calculate the area with hist[tp] stack as smallest bar and update max area, if needed
            max_area = max(max_area, (hist[s.top()]*(s.empty() ? i : i - s.top() - 1)));
            s.pop();  // pop the top
        }
    }
// Now pop the remaining bars from stack and calculate area with every popped bar as the smallest bar
    while (!s.empty()){
        max_area = max(max_area, (hist[s.top()]*(s.empty() ? i : i - s.top() - 1)));
        s.pop();
    }
    return max_area;
}
int main(){// Driver program to test above function
    int hist[] = {6, 2, 5, 4, 5, 1, 6}, n = sizeof(hist)/sizeof(hist[0]);
    cout << "Maximum area is " << getMaxArea(hist, n);
    return 0;
}
