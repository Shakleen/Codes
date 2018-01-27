#include <bits/stdc++.h>

using namespace std;

//*******************************************************************************
//*******************************Template****************************************
//*******************************************************************************

#define eps                 1e-6
#define ll                  long long
#define llu                 long long unsigned
#define ld                  long double
#define REP(i,n)            for(int i = 0; i < n; i++)
#define FLR(i,n)            for(ll i = 0; i < n; i++)
#define ROF(i,n)            for(int i = n-1; i >= 0; i--)
#define FOR(i,a,b)          for(int i = a; i <= b; i++)
#define FORL(i,a,b)         for(ll i = a; i <= b; i++)
#define casep(z)            printf("Case %d:", z);
#define sz(a)               a.size()
#define all(x)              x.begin(),x.end()
#define SORT(a,n)           sort(a,a+n)
#define RSORT(a,n)          sort(a,a+n,greater<ll>())
#define VSORT(v)            sort(all(v))
#define VRSORT(v)           sort(all(v),greater<ll>())
#define pii                 pair <int, int>
#define pll                 pair <ll, ll>
#define pb                  push_back
#define pf                  push_front
#define pob                 pop_back()
#define pof                 pop_front()
#define ff                  first
#define ss                  second
#define mp                  make_pair
#define ms(x,n)             memset((x),n,sizeof(x))
#define fin                 freopen("in.txt", "r", stdin)
#define fout                freopen("out.txt", "w", stdout)
#define IT(it,x)            for(it=x.begin(); it != x.end(); it++)
#define sf1(x)              scanf("%d", &x)
#define sfl1(x)             scanf("%lld", &x)
#define MOD                 1000000007

ll bigMod(ll base, ll power){
    ll res = 1;
    while(power){
        if(power&1)     res = (res * base) % MOD;
        base = (base * base) % MOD;
        power >>= 1LL;
    }
    return res;
}

ll gcd(ll a, ll b){
    ll c = 0;
    while(b){
        if(!b)  break;
        c = a%b;
        a = b;
        b = c;
    }
    return a;
}

int main(){
    //freopen("input.txt","r",stdin);
    //freopen("output.txt","w",stdout);

//    clock_t begin, end;
//    double time_spent;
//    begin = clock();

    int t=0;
    ll n=0, k=0, sum=0;

    sf1(t);

    FOR(tc,1,t){
        scanf("%d %d", &n, &k);

        sum = 0;

        FOR(i,1,n){
            sum = (sum + bigMod(k, gcd(n,i))) % MOD;
        }

        sum = (sum * bigMod(n, MOD-2)) % MOD;

        casep(tc);
        printf(" %lld\n", sum);
    }


//    end = clock();
//    time_spent = (double)(end-begin)/CLOCKS_PER_SEC;
//    printf("TIme spent = %lf", time_spent);
    return 0;
}

/*
The last TopCoder SRM (the problem statement is at http://www.topcoder.com/stat?c=problem_statement&pm=9975,
but that requires a TopCoder account to view) has inspired me to write about a small and quite easy fact in
group theory which I think was the most useful part of group theory for me in programming competitions.
It's called Burnside's lemma and says (citing from Wikipedia): let G be a finite group that acts on a set X.
Then the number of orbits is equal to the average number of points fixed by an element of G. What does this
all mean and how is this applicable to programming competitions? Let's continue with an example.
A standard problem that is best solved using Burnside's lemma is: consider a circular stripe of n cells. How
many ways are there to color these cells with two colors, black and white, up to a rotation? Here, X is a set
of all colored stripes (it has 2^n elements), and G is the group of its rotations (it has n elements: rotation
by 0 cells, by 1 cell, by 2 cells, etc, by (n-1) cells), and an orbit is exactly the set of all stripes that can
be obtained from each other using rotations, so the number of orbits will be the number of distinct stripes up
to a rotation. Now let's apply the lemma, and find the number of stripes that are fixed by the rotation by K cells.
If a stripe becomes itself after rotating by K cells, then its 1st cell must have the same color as its
(1+K modulo n)-th cell, which is in turn the same as its (1+2K modulo n)-th cell, etc, until we get back to the
1st cell when m*K modulo n=0. One may notice that this will happen when m=n/gcd(K,n), and thus we get n/gcd(K,n)
cells that must all be of the same color. Analogously, the same amount of cells must be of the same color starting
with cell 2, (2+K modulo n), etc. Thus, all cells are separated into gcd(K,n) groups, with each group being of
one color, and that yields us 2^gcd(K,n) choices. And by Burnside's lemma, the answer to the original problem is
sum(2^gcd(K,n))/n, where the sum is taken over K from 0 to n-1.
That was rather complicated; here's a somewhat simpler example: Consider a square of 2n times 2n cells.
How many ways are there to color it into X colors, up to rotations and/or reflections? Here, the group
has only 8 elements (rotations by 0, 90, 180 and 270 degrees, reflections over two diagonals, over a vertical
line and over a horizontal line). Every coloring stays itself after rotating by 0 degrees, so that rotation has
X^(4n^2) fixed points. Rotation by 180 degrees and reflections over a horizontal/vertical line split all cells in
pairs that must be of the same color for a coloring to be unaffected by such rotation/reflection, thus there exist
X^(2n^2) such colorings for each of them. Rotations by 90 and 270 degrees split cells in groups of four, thus
yielding X^(n^2) fixed colorings. Reflections over diagonals split cells into 2n groups of 1 (the diagonal itself)
and (2n^2-n) groups of 2 (all remaining cells), thus yielding X^(2n^2-n+2n)=X^(2n^2+n) unaffected colorings. So,
the answer is (X^(4n^2)+3*X^(2n^2)+2*X^(n^2)+2*X^(2n^2+n))/8.
I understand that this looks kind of too much formulas for too little gain, but once you get the hang of it, it
becomes really simple and easy to use.
And as a plus, you get to verify that you haven't made a bug: the lemma has a division in the end (e.g., the
division by 8 in the last formula). If that division produces a remainder, you ve miscalculated somewhere. And
chances are, if you have made a mistake, feeding the program random testcases will make the formula produce a
remainder quite soon.
P.S. The Formula 1 GP at Interlagos starts in 20 minutes! I will be rooting for Massa to win the championship (I don't exactly know why - maybe because he's losing :)). The event is very likely to turn out quite exciting
*/
